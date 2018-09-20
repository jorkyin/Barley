package com.jorkyin.barley.model;

import android.util.Log;
import com.jorkyin.barley.util.P2PParam;
import org.greenrobot.eventbus.EventBus;

public class NativeCaller {
    static {
        System.loadLibrary("native");
    }
    //设置回调的类
    public static native int setCallBackContext(Object object);
    //初始化SDK
    public static native int RTSDKInit();
    //开始搜索局域网内部的UID
    public static native void StartSearchDev();
    //结束搜索局域网内部的UID
    public static native void StopSearchDev();
    //链接设备
    public static native void StartConnectDev(String UID, String user, String password, String userData);//userData 由用户输入,从实时码流回调进行返回);
    //断开设备链接
    public static native void StopConnectDev(String UID);




}
