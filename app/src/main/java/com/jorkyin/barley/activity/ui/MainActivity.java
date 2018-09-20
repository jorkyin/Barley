package com.jorkyin.barley.activity.ui;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.view.View;
import android.view.Window;
import android.widget.Toast;

import com.google.gson.Gson;
import com.jorkyin.barley.R;
import com.jorkyin.barley.activity.RecyclerAdapter.CameraRecyclerAdapter;
import com.jorkyin.barley.SQL.DatabaseHelper;
import com.jorkyin.barley.base.OnClickItemViewListener;
import com.jorkyin.barley.model.NativeCallBack;
import com.jorkyin.barley.model.NativeCaller;
import com.jorkyin.barley.util.Const;
import com.jorkyin.barley.util.P2PParam;
import com.jorkyin.barley.util.PermissionHandle;
import com.jorkyin.barley.util.RecyclerItemDecoration;

import org.greenrobot.eventbus.EventBus;
import org.greenrobot.eventbus.Subscribe;
import org.greenrobot.eventbus.ThreadMode;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";
    private RecyclerView recyclerView;
    private ArrayList<P2PParam> mData;
    private CameraRecyclerAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        // 隐藏当前Activity的标题
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        setContentView(R.layout.activity_main);

        PermissionHandle.requireSomePermission(this);// 申请权限;
        Log.i(TAG, "onCreate: ");
        recyclerView = findViewById(R.id.camera_Recycler_view);
        findViewById(R.id.main_add_camera).setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {
                Intent intent = new Intent(MainActivity.this, AddActivity.class);

                intent.putExtra(Const.DATALIST, new Gson().toJson(mData));
                startActivityForResult(intent, Const.MAINACTIVITY_AADACTIVITY_TITLE);
            }
        });
        Log.i(TAG, "onCreate: 3");
        //从数据库里面获取已经添加的设备
        mData = new DatabaseHelper(this).getCamInfo();

        Log.i(TAG, "onCreate: 4");
        //初始化RecyclerView,用于显示item样式
        showView();
        Log.i(TAG, "onCreate: 5");
        //注册C回调Java方法
        NativeCallBack.getInstance();
        Log.i(TAG, "onCreate: 6");
        //初始化P2P，并注册回调函数
        NativeCaller.RTSDKInit();
        Log.i(TAG, "onCreate: 7");


        //注册订阅者,用于C回调Java的方法，更新UI
        EventBus.getDefault().register(this);
    }

    @Override
    protected void onStart() {
        super.onStart();
        for (int i=0;i<mData.size();i++){
NativeCaller.StartConnectDev(mData.get(i).getUID(),mData.get(i).getUser(),mData.get(i).getPassword(),"");
        }
    }

    //定义处理接收的方法，更新UI
    @Subscribe(threadMode = ThreadMode.MAIN)
    public void userEventBus(P2PParam p2PParam) {
        for (int i = 0; i < mData.size(); i++) {
            if (mData.get(i).getUID().equals(p2PParam.getUID())) {
                mData.get(i).setState(p2PParam.getState());
                adapter.updateData(mData);
                break;
            }
        }
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
        //注销注册
        EventBus.getDefault().unregister(this);
    }

    private void showView() {
        RecyclerView.LayoutManager layoutManager = new LinearLayoutManager(this, LinearLayoutManager.VERTICAL, false);
        adapter = new CameraRecyclerAdapter(mData);
        adapter.setOnClickItemViewListener(new OnClickItemViewListener() {
            @Override
            public void onRecyclerViewItemClick(View view, int position) {
                switch (view.getId()) {
                    case R.id.item_camera_image:
                       /* if (mData.get(position).getState() == null) {
                            NativeCaller.ConnectDev(mData.get(position).getUID(), mData.get(position).getUser(), mData.get(position).getPassword());
                        } else {
                            Intent intent = new Intent(MainActivity.this, LiveActivity.class);
                            intent.putExtra(Const.P2PPARAM, new Gson().toJson(mData.get(position)));
                            startActivity(intent);
                        }*/

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
            }
        });

        // 设置布局管理器
        recyclerView.setLayoutManager(layoutManager);
        recyclerView.addItemDecoration(new RecyclerItemDecoration(this, LinearLayoutManager.VERTICAL));

        //设置Adapter参数
        recyclerView.setAdapter(adapter);
    }
}
