package com.jorkyin.barley.model;

import android.content.Context;
import android.os.Bundle;
import android.util.Log;

import org.greenrobot.eventbus.EventBus;

public class NativeCallBack {

    private final static String TAG = "RTNativeCallBack";
    public final static String CALLBACKTYPE = "CallBackType";
    public final static class CallBackType{
        public final static String CALL_BACK_TYPE_CAMERA_SEARCH = "call_back_type_camera_search";
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

    }

}


