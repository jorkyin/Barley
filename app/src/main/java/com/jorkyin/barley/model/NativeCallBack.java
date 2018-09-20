package com.jorkyin.barley.model;

import android.os.Bundle;
import android.util.Log;

import org.greenrobot.eventbus.EventBus;

import static com.jorkyin.barley.util.Const.MSG_NOTIFY_TYPE_PPPP_MODE;
import static com.jorkyin.barley.util.Const.MSG_NOTIFY_TYPE_PPPP_STATUS;
import static com.jorkyin.barley.util.Const.MSG_NOTIFY_TYPE_STREAM_TYPE;
import static com.jorkyin.barley.util.Const.MSG_NOTIFY_TYPE_TALK_STATUS;

public class NativeCallBack {

    private final static String TAG = "RTNativeCallBack";
    public final static String CALLBACKTYPE = "CallBackType";
    public final static class CallBackType{
        public final static String CALL_BACK_TYPE_CAMERA_SEARCH = "call_back_type_camera_search";
        public final static String CALL_BACK_TYPE_P2P_STATUS = "call_back_type_p2p_status";
        public final static String CALL_BACK_TYPE_P2P_MODE = "call_back_type_p2p_mode";
        public final static String CALL_BACK_TYPE_CAMERA_STREAM_TYPE = "call_back_type_camera_strera_type";
        public final static String CALL_BACK_TYPE_CAMERA_TALK_STATUS= "call_back_type_camera_talk_status";
    }
    private static NativeCallBack mNativeCallBack;

    public static NativeCallBack getInstance() {
        if (mNativeCallBack == null) {
            mNativeCallBack = new NativeCallBack();
        }
        return mNativeCallBack;
    }

    public static void destoryCallBack(){
            mNativeCallBack=null;
    }

    public NativeCallBack() {
        NativeCaller.setCallBackContext(this);
    }


    /**
     * 搜索摄像头，会将搜索到的摄像头回调回来
     */
    private void CallBack_SearchResult(String strMac, String strName, String strDeviceID, String strIpAddr, int port) {
        EventBus mEventBus = EventBus.getDefault();
        Bundle bundle = new Bundle();
        bundle.putString(CALLBACKTYPE, CallBackType.CALL_BACK_TYPE_CAMERA_SEARCH);
        Log.i(TAG, "CallBack_SearchResult: Mac="+strMac+" strName="+strName
                +" strDeviceID="+strDeviceID+" strIpAddr="+strIpAddr+" port="+port);
        bundle.putString("mac", strMac);
        bundle.putString("devName", strName);
        bundle.putString("devDid", strDeviceID);
        bundle.putString("ipAddr", strIpAddr);
        bundle.putInt("port", port);
        mEventBus.post(bundle);//将搜索回来的摄像头信息发送给AddCameraPresenter

    }

    //连接设备回调
    private void CallBack_ConnectDev(String uid, int msgTye,int msgValue) {
        Log.i(TAG, "CallBack_SearchResult: uid="+uid+" msgTye="+msgTye
                +" msgValue="+msgValue);
        EventBus mEventBus = EventBus.getDefault();
        Bundle bundle = new Bundle();
        bundle.putString("uid", uid);
        bundle.putInt("msgValue", msgValue);
        switch (msgTye){
            case MSG_NOTIFY_TYPE_PPPP_STATUS: /* p2p连接状态*/
                bundle.putString(CALLBACKTYPE, CallBackType.CALL_BACK_TYPE_P2P_STATUS);
                break;
            case MSG_NOTIFY_TYPE_PPPP_MODE:   /* p2p类型*/
                bundle.putString(CALLBACKTYPE, CallBackType.CALL_BACK_TYPE_P2P_MODE);
                break;
            case MSG_NOTIFY_TYPE_STREAM_TYPE:  //视频流类型
                bundle.putString(CALLBACKTYPE, CallBackType.CALL_BACK_TYPE_CAMERA_STREAM_TYPE);
                break;
            case MSG_NOTIFY_TYPE_TALK_STATUS:  /*音频对讲*/
                bundle.putString(CALLBACKTYPE, CallBackType.CALL_BACK_TYPE_CAMERA_TALK_STATUS);
                break;
        }
        mEventBus.post(bundle);
    }

}


