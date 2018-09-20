package com.jorkyin.barley.model;

import android.graphics.SurfaceTexture;
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
    //连接设备
    public static native void StartConnectDev(String UID, String user, String password, String userData);//userData 由用户输入,从实时码流回调进行返回);
    //断开设备链接
    public static native void StopConnectDev(String UID);
    //开启视频流
    public static native int StartLiveStream(String UID, int streamid);// 3:720P   1:QVGA		 0:VGA
    //停止视频流
    public static native int StopLiveStream(String UID);
    //切换视频流
    public static native int SwitchLiveStream(String UID, int streamid);// 3:720P   1:QVGA		 0:VGA
    //开启监听
    public static native int StartLiveAudio(String UID, int audioType);// 3:720P   1:QVGA		 0:VGA
    //停止监听
    public static native int StopLiveAudio(String UID);
    //开启音频对讲
    public static native int StartLiveTalk(String UID);
    //发送对讲音频数据
    public static native int StartLiveTalkAudioData(String UID, int streamid);
    //停止音频对讲
    public static native int StopLiveTalk(String UID);
    //停止音频对讲
    public static native int InitFFmpeg(SurfaceTexture surface);





}
