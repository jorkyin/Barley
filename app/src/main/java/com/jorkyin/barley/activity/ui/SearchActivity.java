package com.jorkyin.barley.activity.ui;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.view.View;

import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;
import com.jorkyin.barley.R;
import com.jorkyin.barley.activity.RecyclerAdapter.SearchRecyclerAdpter;
import com.jorkyin.barley.activity.presenter.SearchPresenter;
import com.jorkyin.barley.base.OnClickItemViewListener;
import com.jorkyin.barley.util.Const;
import com.jorkyin.barley.util.P2PParam;
import com.jorkyin.barley.util.RecyclerItemDecoration;
import java.util.ArrayList;

public class SearchActivity extends AppCompatActivity{

    private static final String TAG = "SearchActivity";
    private ArrayList<P2PParam> mData;//列表显示uids
    private ArrayList<P2PParam> mExistData;//服务器总的uids
    private RecyclerView mRecyclerView;
    private SearchRecyclerAdpter mAdpter;
    private SearchPresenter mSearchPresenter;
    TopMenuHeader mTopMenuHeader;//标题栏
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_search);
        mRecyclerView = findViewById(R.id.search_uid_recycler_view);

        mData = new ArrayList<>();
        //Log.e(TAG, jsonData);
        String jsonData = getIntent().getStringExtra(Const.DATALIST);
        mExistData = new Gson().fromJson(jsonData, new TypeToken<ArrayList<P2PParam>>() {
        }.getType());
        mSearchPresenter=new SearchPresenter();
        initActivity();
    }
    private void initActivity() {
        if (mTopMenuHeader==null){//初始化标题栏
            mTopMenuHeader = new TopMenuHeader(findViewById(R.id.title_layout));
            initTopMenuTitle();
        }

        RecyclerView.LayoutManager layoutManager = new LinearLayoutManager(this, LinearLayoutManager.VERTICAL, false);
        mAdpter = new SearchRecyclerAdpter();
        mAdpter.setOnItemClickListener(new OnClickItemViewListener() {
            @Override
            public void onRecyclerViewItemClick(View view, int position) {
                //Log.i("SearchActivity", "onClick: " + position);
                Intent intent = new Intent();
                intent.putExtra(Const.UID, mData.get(position).getUID());
                setResult(Const.AADACTIVITY_SEARCHACTIVITY_TITLE, intent);
                finish();
            }
        });

        mRecyclerView.setLayoutManager(layoutManager);
        mRecyclerView.addItemDecoration(new RecyclerItemDecoration(this, LinearLayoutManager.VERTICAL));
        mRecyclerView.setAdapter(mAdpter);
    }

    //初始化标题栏
    private void initTopMenuTitle() {
        mTopMenuHeader.topMenuTitle.setText("局域网搜索");
        mTopMenuHeader.topMenuLeft.setVisibility(View.VISIBLE);
        mTopMenuHeader.topMenuLeft.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent();
                setResult(Const.AADACTIVITY_SEARCHACTIVITY_TITLE, intent);
                finish();
            }
        });
    }
    @Override
    protected void onStart() {
        super.onStart();
        mSearchPresenter.onStart();
        mSearchPresenter.setSearchCallBackListener(new SearchPresenter.SearchCallBackListener() {
            @Override
            public void newSearchCallBack(P2PParam p2PParam) {
                for (int i = 0; i < mData.size(); i++) {
                    if (mData.get(i).getUID().equals(p2PParam.getUID())) {
                        return;
                    }
                }
                for (int i = 0; i < mExistData.size(); i++) {
                    if (mExistData.get(i).getUID().equals(p2PParam.getUID())) {
                        p2PParam.setStateString("已添加");
                        break;
                    }
                }
                mData.add(p2PParam);
                mAdpter.updateData(mData);
            }
        });
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mSearchPresenter.onDestroy();
    }

    //手机返回按钮监听
    @Override
    public void onBackPressed() {
        super.onBackPressed();

        Intent intent = new Intent();
        setResult(Const.AADACTIVITY_SEARCHACTIVITY_TITLE, intent);
        finish();
    }
}
