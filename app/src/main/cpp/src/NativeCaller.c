//
// Created by yinjian on 2017/11/11.
//


#include <java_jni_RTMap.h>
#include "NativeCaler.h"
#include "h264_decoder.h"

//设置回调的类

JNIEXPORT jint JNICALL
Java_com_jorkyin_barley_model_NativeCaller_setCallBackContext(JNIEnv *env, jclass type,
                                                              jobject object) {

//初始化java回调中的方法，用于将消息已反向调用的方式返回回去
    if(NativeCallBack_init(env,type,object)!=0){
        return -1;
    }


    return 0;
}

//初始化SDK
JNIEXPORT jint JNICALL
Java_com_jorkyin_barley_model_NativeCaller_RTSDKInit(JNIEnv *env, jclass type) {

    RT_APP_Params appInitParams;
    memset(&appInitParams,0, sizeof(RT_APP_Params));

    /*回调注册区*/
    //获取信息回调
    appInitParams.getMsgDataCallBack = rtGetMsgDataCallBack;
    //设置信息回调
    appInitParams.setMsgReturnCallBack = rtSetMsgReturnCallBack;
    //连接回调
    appInitParams.connectStatusCallBack = rtConnectCallBack;
    //搜索回调
    appInitParams.searchDataCallBack = rtSearchDataCallBack;
    //直播回调
    appInitParams.h264VideoPlayerCallBack = rtH264VideoPlayerCallBack;
    //回播回调
    appInitParams.h264PlayBackCallBack = rtH264PlayBackCallBack;
    //其他流
    //appInitParams.otherVideoPlayerCallBack = rtOtherVideoPlayerCallBack;
    //音频
    appInitParams.audioPlayerCallBack = audioPlayerCallBack;
    //告警
    appInitParams.alarmCallBack = rtAlarmBackCallBack;
    //下载图片回调
    appInitParams.loadPicCallBack = rtDownLoadPictureCallBack;
    //下载视频回调
    appInitParams.loadVidCallBack = rtDownLoadVideoCallBack;
    //日志回调
    //RT_LOG_REGISTER_CALL_Back(showLog1);

    if (RT_APP_API_Initial(&appInitParams) != 0){
        LOGD("-----------RT_APP_API_Initial failed-------------\n");
        return -1;
    }

    //初始化map
    RT_InitMap();

    return 0;
}


//开始搜索局域网内部的UID
JNIEXPORT void JNICALL
Java_com_jorkyin_barley_model_NativeCaller_StartSearchDev(JNIEnv *env, jclass type) {

    RT_APP_API_SEARCH_DEV_Start();

}
//结束搜索局域网内部的UID
JNIEXPORT void JNICALL
Java_com_jorkyin_barley_model_NativeCaller_StopSearchDev(JNIEnv *env, jclass type) {

    RT_APP_API_SEARCH_DEV_Stop();

}
//链接设备
JNIEXPORT void JNICALL
Java_com_jorkyin_barley_model_NativeCaller_StartConnectDev(JNIEnv *env, jclass type, jstring UID_,
                                                           jstring user_, jstring password_,
                                                           jstring userData_) {
    const char *UID = (*env)->GetStringUTFChars(env, UID_, 0);
    const char *user = (*env)->GetStringUTFChars(env, user_, 0);
    const char *password = (*env)->GetStringUTFChars(env, password_, 0);
    const char *userData = (*env)->GetStringUTFChars(env, userData_, 0);
    RT_APP_UPTR u32AppHandle=0;
    RT_APP_API_Start(&u32AppHandle, (RT_APP_CHAR *) UID, (RT_APP_CHAR *) user,
                     (RT_APP_CHAR *) password, (void *) userData);

    //将handle保存到Map中
    RT_DeleteHanleFromMap(UID);
    RT_AddHandleToMap(UID, u32AppHandle);

    (*env)->ReleaseStringUTFChars(env, UID_, UID);
    (*env)->ReleaseStringUTFChars(env, user_, user);
    (*env)->ReleaseStringUTFChars(env, password_, password);
    (*env)->ReleaseStringUTFChars(env, userData_, userData);
}

//断开设备链接
JNIEXPORT void JNICALL
Java_com_jorkyin_barley_model_NativeCaller_StopConnectDev(JNIEnv *env, jclass type, jstring UID_) {
    const char *UID = (*env)->GetStringUTFChars(env, UID_, 0);
    RT_APP_UPTR u32AppHandle=0;
    RT_GetHandleFromMap(UID, &u32AppHandle);

    RT_APP_API_Stop(u32AppHandle, (RT_APP_CHAR *) UID);

    //删除map中的handle
    RT_DeleteHanleFromMap(UID);
    (*env)->ReleaseStringUTFChars(env, UID_, UID);
}