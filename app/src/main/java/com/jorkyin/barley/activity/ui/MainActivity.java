package com.jorkyin.barley.activity.ui;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.view.View;
import android.view.Window;
import android.widget.Toast;

import com.google.gson.Gson;
import com.jorkyin.barley.R;
import com.jorkyin.barley.activity.RecyclerAdapter.CameraRecyclerAdapter;
import com.jorkyin.barley.SQL.DatabaseHelper;
import com.jorkyin.barley.activity.presenter.MainPresenter;
import com.jorkyin.barley.base.OnClickItemViewListener;
import com.jorkyin.barley.model.NativeCallBack;
import com.jorkyin.barley.model.NativeCaller;
import com.jorkyin.barley.util.Const;
import com.jorkyin.barley.util.P2PParam;
import com.jorkyin.barley.util.PermissionHandle;
import com.jorkyin.barley.util.RecyclerItemDecoration;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";
    private RecyclerView recyclerView;
    private ArrayList<P2PParam> mData;
    private CameraRecyclerAdapter adapter;
    private MainPresenter presenter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        // 隐藏当前Activity的标题
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        setContentView(R.layout.activity_main);

        PermissionHandle.requireSomePermission(this);// 申请权限;
        recyclerView = findViewById(R.id.camera_Recycler_view);
        findViewById(R.id.main_add_camera).setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {
                Intent intent = new Intent(MainActivity.this, AddActivity.class);

                intent.putExtra(Const.DATALIST, new Gson().toJson(mData));
                startActivityForResult(intent, Const.MAINACTIVITY_AADACTIVITY_TITLE);
            }
        });
        //从数据库里面获取已经添加的设备
        mData = new DatabaseHelper(this).getCamInfo();
        //初始化RecyclerView,用于显示item样式
        showView();
        //注册C回调Java方法
        NativeCallBack.getInstance();
        //初始化P2P，并注册回调函数
        NativeCaller.RTSDKInit();

        presenter =new MainPresenter();
    }

    @Override
    protected void onStart() {
        super.onStart();
        presenter.onStart(mData);
        presenter.setP2PStatusCallBackListener(new MainPresenter.P2PStatusCallBackListener() {
            @Override
            public void P2PStatusCallBack(String uid, String msgString, int msgValue) {
                for (int i=0;i<mData.size();i++){
                    if (uid.equals(mData.get(i).getUID())){
                        mData.get(i).setStateString(msgString);
                        mData.get(i).setStateValue(msgValue);
                        adapter.updateData(mData);
                        return;
                    }
                }
            }
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == Const.MAINACTIVITY_AADACTIVITY_TITLE && data != null) {
            P2PParam CamInfo = new P2PParam(data.getStringExtra(Const.NAME),
                    data.getStringExtra(Const.UID),
                    data.getStringExtra(Const.USER),
                    data.getStringExtra(Const.PASSWORD));
            new DatabaseHelper(this).addCamInfo(CamInfo);
            mData.add(CamInfo);
            adapter.updateData(mData);
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        presenter.onDestroy(mData);
    }

    private void showView() {
        RecyclerView.LayoutManager layoutManager = new LinearLayoutManager(this, LinearLayoutManager.VERTICAL, false);
        adapter = new CameraRecyclerAdapter(mData);
        adapter.setOnClickItemViewListener(new OnClickItemViewListener() {
            @Override
            public void onRecyclerViewItemClick(View view, int position) {
                if (mData.get(position).getStateValue()==Const.PPPP_STATUS_ON_LINE){
                switch (view.getId()) {
                    case R.id.item_camera_image:
                        Intent intent = new Intent(MainActivity.this, LiveActivity.class);
                        intent.putExtra(Const.P2PPARAM, new Gson().toJson(mData.get(position)));
                        startActivity(intent);
                        break;
                    case R.id.item_camera_folder:
                        startActivity(new Intent(MainActivity.this, FolderActivity.class));
                        break;
                    case R.id.item_camera_set:
                        startActivity(new Intent(MainActivity.this, ConfigActivity.class));
                        Toast.makeText(MainActivity.this, position + " item_camera_set", Toast.LENGTH_SHORT).show();
                        break;
                }
                }else {
                    //presenter.p2pConnectDev(mData.get(position));
                    Toast.makeText(MainActivity.this, "设备连接失败", Toast.LENGTH_SHORT).show();
                }
            }
        });

        // 设置布局管理器
        recyclerView.setLayoutManager(layoutManager);
        recyclerView.addItemDecoration(new RecyclerItemDecoration(this, LinearLayoutManager.VERTICAL));

        //设置Adapter参数
        recyclerView.setAdapter(adapter);
    }
}
