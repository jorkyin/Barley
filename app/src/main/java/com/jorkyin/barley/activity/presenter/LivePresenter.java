package com.jorkyin.barley.activity.presenter;

import android.graphics.SurfaceTexture;
import android.os.Bundle;
import android.view.Surface;

import com.jorkyin.barley.model.NativeCallBack;
import com.jorkyin.barley.model.NativeCaller;
import com.jorkyin.barley.util.Const;
import com.jorkyin.barley.util.P2PParam;

import org.greenrobot.eventbus.EventBus;
import org.greenrobot.eventbus.Subscribe;
import org.greenrobot.eventbus.ThreadMode;

import java.util.ArrayList;

import static com.jorkyin.barley.util.Const.PPPP_STATUS_CONNECTING;
import static com.jorkyin.barley.util.Const.PPPP_STATUS_CONNECT_FAILED;
import static com.jorkyin.barley.util.Const.PPPP_STATUS_CONNECT_TIMEOUT;
import static com.jorkyin.barley.util.Const.PPPP_STATUS_DEVICE_NOT_ON_LINE;
import static com.jorkyin.barley.util.Const.PPPP_STATUS_DISCONNECT;
import static com.jorkyin.barley.util.Const.PPPP_STATUS_INITIALING;
import static com.jorkyin.barley.util.Const.PPPP_STATUS_INVALID_ID;
import static com.jorkyin.barley.util.Const.PPPP_STATUS_INVALID_USER_PWD;
import static com.jorkyin.barley.util.Const.PPPP_STATUS_MAX_CONNECT_CNT;
import static com.jorkyin.barley.util.Const.PPPP_STATUS_ON_LINE;

public class LivePresenter {

    public LivePresenter() {
        EventBus.getDefault().register(this);
    }

    //事件订阅者处理事件
    @Subscribe(threadMode = ThreadMode.MAIN)
    public void p2pStatusCallBack(Bundle bundle) {
        String callBackType = bundle.getString(NativeCallBack.CALLBACKTYPE);

        if (callBackType != null && callBackType.equals(NativeCallBack.CallBackType.CALL_BACK_TYPE_P2P_STATUS)) {
            int msgValue = bundle.getInt("msgValue");
            String uid = bundle.getString("uid");
            switch (msgValue) {
                case PPPP_STATUS_CONNECTING:/* 正在连接 */
                    mP2PStatusCallBackListener.P2PStatusCallBack(uid, "正在连接", msgValue);
                    break;
                case PPPP_STATUS_INITIALING:/* 启动连接 */
                    mP2PStatusCallBackListener.P2PStatusCallBack(uid, "启动连接", msgValue);
                    break;
                case PPPP_STATUS_ON_LINE: /* 设备在线 */
                    mP2PStatusCallBackListener.P2PStatusCallBack(uid, "设备在线", msgValue);
                    break;
                case PPPP_STATUS_CONNECT_FAILED:/* 连接失败 */
                    mP2PStatusCallBackListener.P2PStatusCallBack(uid, "连接失败", msgValue);
                    break;
                case PPPP_STATUS_DISCONNECT: /* 连接断开*/
                    mP2PStatusCallBackListener.P2PStatusCallBack(uid, "连接断开", msgValue);
                    break;
                case PPPP_STATUS_INVALID_ID:/* 无效UID*/
                    mP2PStatusCallBackListener.P2PStatusCallBack(uid, "无效UID", msgValue);
                    NativeCaller.StopConnectDev(uid);
                    break;
                case PPPP_STATUS_DEVICE_NOT_ON_LINE:/*设备不在线*/
                    mP2PStatusCallBackListener.P2PStatusCallBack(uid, "设备不在线", msgValue);
                    NativeCaller.StopConnectDev(uid);
                    break;
                case PPPP_STATUS_CONNECT_TIMEOUT:/* 连接超时 */
                    mP2PStatusCallBackListener.P2PStatusCallBack(uid, "连接超时", msgValue);
                    NativeCaller.StopConnectDev(uid);
                    break;
                case PPPP_STATUS_INVALID_USER_PWD:/* 用户名或者密码错误 */
                    mP2PStatusCallBackListener.P2PStatusCallBack(uid, "用户名或者密码错误", msgValue);
                    NativeCaller.StopConnectDev(uid);
                    break;
                case PPPP_STATUS_MAX_CONNECT_CNT:/*超过设备端的最大连接数*/
                    mP2PStatusCallBackListener.P2PStatusCallBack(uid, "超过最大连接数", msgValue);
                    NativeCaller.StopConnectDev(uid);
                    break;
            }
        }
    }

    public void onStart(P2PParam p2PParam) {
    }


    public void onDestroy(ArrayList<P2PParam> mData) {
        //取消注册EventBus事件
        EventBus.getDefault().unregister(this);
        for (int i = 0; i < mData.size(); i++) {
            NativeCaller.StopConnectDev(mData.get(i).getUID());
        }
    }

    private P2PStatusCallBackListener mP2PStatusCallBackListener;

    public void setP2PStatusCallBackListener(P2PStatusCallBackListener p2PStatusCallBackListener) {
        this.mP2PStatusCallBackListener = p2PStatusCallBackListener;
    }

    public void player(SurfaceTexture surface) {
        NativeCaller.InitFFmpeg(surface);
    }

    //
    public interface P2PStatusCallBackListener {
        void P2PStatusCallBack(String uid, String msgString, int msgValue);
    }
}
