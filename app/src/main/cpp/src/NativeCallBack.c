//
// Created by jorkyin on 18-3-1.
//

#include <h264_decoder.h>
#include "NativeCallBack.h"

RT_APP_INT32 g_onLine = 0;
RT_APP_INT32 g_sendTalk = 0;
//全局变量
CALLBACK_HANDLE g_callBackHandle;
jmethodID g_CallBack_SearchResult = NULL;
jmethodID g_CallBack_ConnectDev = NULL;


/**
* 通过全局变量g_JavaVM获取JNIEnv
*/
int RT_GetEnv(JNIEnv **env) {
    int cRet = 0;

    if (g_callBackHandle.javaVM == NULL) {
        //LOGD("[%s	%d] javaVM NULL\n",__FUNCTION__,__LINE__);
        return -1;
    }

    jint status = (*g_callBackHandle.javaVM)->GetEnv(g_callBackHandle.javaVM, (void **) env,
                                                     JNI_VERSION_1_4);

    if (status < 0) {
        //将当前的线程绑定到jvm虚拟机线程当中，并获取env
        status = (*g_callBackHandle.javaVM)->AttachCurrentThread(g_callBackHandle.javaVM, env,
                                                                 NULL);
        if (status < 0) {
            //LOGD("[%s	%d] AttachCurrentThread Faile\n",__FUNCTION__,__LINE__);
            return -1;
        }
        cRet = 1;
    }
    return cRet;
}

//初始化回调方法
int NativeCallBack_init(JNIEnv *env, jclass cls, jobject context) {
    memset(&g_callBackHandle, 0, sizeof(CALLBACK_HANDLE));
    if (context == NULL) {
        g_CallBack_SearchResult = NULL;
        g_CallBack_ConnectDev = NULL;
        return -1;
    }

    //获取jvm(虚拟机)
    (*env)->GetJavaVM(env, &g_callBackHandle.javaVM);
    //新建全局变量
    g_callBackHandle.callBackObj = (*env)->NewGlobalRef(env, context);
    //获取当前类对象
    jclass clazz = (*env)->GetObjectClass(env, context);

    //jni反向调用
    g_CallBack_SearchResult = (*env)->GetMethodID(env, clazz, "CallBack_SearchResult",
                                                  "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V");
    g_CallBack_ConnectDev = (*env)->GetMethodID(env, clazz, "CallBack_ConnectDev",
                                                "(Ljava/lang/String;II)V");

    return 0;
}


//销毁回调方法
void RT_Callback_free(JNIEnv *env) {

    //删除全局变量
    (*env)->DeleteGlobalRef(env, g_callBackHandle.callBackObj);
    g_callBackHandle.callBackObj = NULL;

    //销毁虚拟机
    g_callBackHandle.javaVM = NULL;

    g_CallBack_SearchResult = NULL;
    g_CallBack_ConnectDev = NULL;
}


/* 内网搜索设备UID返回回调*/
RT_APP_INT32 rtSearchDataCallBack(RT_APP_CHAR *pbuf) {
    LOGD("[%s   %d]\n", __FUNCTION__, __LINE__);
    JNIEnv *env;
    int cRet = RT_GetEnv(&env);
    if (cRet == -1) {
        return -1;
    }

    //转为jstring
    STRU_SEARCH_PARAMS *pSearchDev = (STRU_SEARCH_PARAMS *) pbuf;
    jstring macAddr = (*env)->NewStringUTF(env, pSearchDev->szMacAddr);
    jstring devName = (*env)->NewStringUTF(env, pSearchDev->szDevName);
    jstring devDid = (*env)->NewStringUTF(env, pSearchDev->szDevUID);
    jstring ipAddr = (*env)->NewStringUTF(env, pSearchDev->szIpAddr);
    jint port = pSearchDev->nPort;

    //LOGD("%s,%s,%s,%s",pSearchDev->szMacAddr,pSearchDev->szDevName,pSearchDev->szDevUID,pSearchDev->szIpAddr);


    (*env)->CallVoidMethod(env, g_callBackHandle.callBackObj, g_CallBack_SearchResult,
                           macAddr, devName, devDid, ipAddr, port);


    //释放临时变量
    (*env)->DeleteLocalRef(env, devDid);
    (*env)->DeleteLocalRef(env, ipAddr);
    (*env)->DeleteLocalRef(env, macAddr);
    (*env)->DeleteLocalRef(env, devName);

    //如果是绑定的方式，要解绑
    if (cRet == 1) {
        (*g_callBackHandle.javaVM)->DetachCurrentThread(g_callBackHandle.javaVM);
    }

    return 0;
}

/* 数据获取回调 */
RT_APP_INT32 rtGetMsgDataCallBack(const RT_APP_CHAR *uid, RT_APP_INT32 msg, RT_APP_CHAR *pbuf,
                                  RT_APP_INT32 len) { return 0; }

/* 设置回调返回值 */
/**pbuf中的值为1时表示用户设置到设备的值是成功,0表示设置失败 */
RT_APP_INT32 rtSetMsgReturnCallBack(const RT_APP_CHAR *uid, RT_APP_INT32 msg, RT_APP_CHAR *pbuf,
                                    RT_APP_INT32 len) {


    return 0;
}


//连接回调
RT_APP_INT32
rtConnectCallBack(const RT_APP_CHAR *uid, RT_APP_INT32 msgType, RT_APP_INT32 msgValue) {
    //LOGD("[%s   %d]\n", __FUNCTION__, __LINE__);
    JNIEnv *env;
    int cRet = RT_GetEnv(&env);
    if (cRet == -1) {
        return -1;
    }
    jstring UID = (*env)->NewStringUTF(env, uid);


    (*env)->CallVoidMethod(env, g_callBackHandle.callBackObj, g_CallBack_ConnectDev, UID, msgType,
                           msgValue);
    //释放临时变量
    (*env)->DeleteLocalRef(env, UID);
    //如果是绑定的方式，要解绑
    if (cRet == 1) {
        (*g_callBackHandle.javaVM)->DetachCurrentThread(g_callBackHandle.javaVM);
    }
    return 0;
}

/*实时码流回调函数*/
/* frametype:0 表示I帧,1 表示P帧*/
RT_APP_INT32
rtH264VideoPlayerCallBack(const RT_APP_CHAR *uid, RT_APP_UCHAR *pbuf, RT_APP_INT32 frametype,
                          RT_APP_UINT32 timestamp, RT_APP_INT32 len,
                          RT_APP_VOID *pOutUserData) {
    static RT_APP_INT32 pframe = 1;
    static RT_APP_INT32 saveTime = 0;


    if (frametype == 1) // P
    {
         LOGI("video[P] uid=%s,pbuf=%x,len=%d P[%02d] time[%d] ", uid, pbuf[6], len, pframe++, timestamp - saveTime);

    } else // I
    {

         LOGI("video[I] uid=%s,pbuf=%x,len=%d", uid, pbuf[6], len, timestamp - saveTime);

        pframe = 1;
    }
    old_speed += len;
    decode_frame(pbuf, len);

    saveTime = timestamp;
    return 0;
}

/*TF远程回放回调函数*/
/* frametype:0 表示I帧,1 表示P帧*/
RT_APP_INT32
rtH264PlayBackCallBack(const RT_APP_CHAR *uid, RT_APP_UCHAR *pbuf, RT_APP_INT32 frametype,
                       RT_APP_UINT32 timestamp, RT_APP_INT32 len) { return 0; }

/*实时音频回调函数*/
RT_APP_INT32
audioPlayerCallBack(const RT_APP_CHAR *uid, RT_APP_UCHAR *pbuf, RT_APP_INT32 len) { return 0; }

/*告警回调函数*/
RT_APP_INT32 rtAlarmBackCallBack(const RT_APP_CHAR *uid, RT_APP_INT32 alarmType,
                                 RT_APP_VOID *pData) { return 0; }

//下载照片回调
RT_APP_INT32
rtDownLoadPictureCallBack(const RT_APP_CHAR *uid, const RT_APP_CHAR *pFileName, RT_APP_UCHAR *pbuf,
                          RT_APP_INT32 len, RT_APP_UCHAR endFlag) { return 0; }

//下载视频回调
RT_APP_INT32
rtDownLoadVideoCallBack(const RT_APP_CHAR *uid, const RT_APP_CHAR *pFileName, RT_APP_UCHAR *pbuf,
                        RT_APP_INT32 len, RT_APP_UCHAR endFlag) { return 0; }
