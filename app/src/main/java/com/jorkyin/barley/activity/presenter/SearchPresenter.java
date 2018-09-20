package com.jorkyin.barley.activity.presenter;

import android.os.Bundle;
import android.util.Log;

import com.jorkyin.barley.model.NativeCallBack;
import com.jorkyin.barley.model.NativeCaller;
import com.jorkyin.barley.util.P2PParam;

import org.greenrobot.eventbus.EventBus;
import org.greenrobot.eventbus.Subscribe;
import org.greenrobot.eventbus.ThreadMode;

public class SearchPresenter {
    private boolean isSearc = false;

    public SearchPresenter() {
        EventBus.getDefault().register(this);
    }

    //事件订阅者处理事件
    @Subscribe(threadMode = ThreadMode.MAIN)
    public void searchCallBack(Bundle bundle) {
        String callBackType = bundle.getString(NativeCallBack.CALLBACKTYPE);

        if (callBackType != null && callBackType.equals(NativeCallBack.CallBackType.CALL_BACK_TYPE_CAMERA_SEARCH)) {
            String Name = bundle.getString("devName");
            String UID = bundle.getString("devDid");
            String IpAddr = bundle.getString("ipAddr");
            String Mac = bundle.getString("mac");
            int port = bundle.getInt("port");

            Log.i("SearchActivity", "onClick: " + UID);


            P2PParam p2PParam = new P2PParam(Name, UID, IpAddr, Mac, port, "admin", "admin");
            mSearchCallBackListener.newSearchCallBack(p2PParam);
        }

    }

    public void onStart() {
        if (!isSearc) {
            //注册C回调java方法
            NativeCaller.StartSearchDev();
            isSearc = true;
        }

    }

    public void onDestroy() {
        if (isSearc) {
            //注册C回调java方法
            NativeCaller.StopSearchDev();
            isSearc = false;
        }
        //取消注册EventBus事件
        EventBus.getDefault().unregister(this);
    }

    private SearchCallBackListener mSearchCallBackListener;

    public void setSearchCallBackListener(SearchCallBackListener searchCallBackListener) {
        this.mSearchCallBackListener = searchCallBackListener;
    }
    //
    public interface SearchCallBackListener {
        void newSearchCallBack(P2PParam p2PParam);
    }
}
