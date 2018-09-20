//
// Created by yinjian on 2018/2/27.
//

#ifndef BARLEY_NATIVE_H
#define BARLEY_NATIVE_H

#include <jni.h>
#include <log.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <wheat_codec.h>
#include <opensl_io.h>
#include <rt_p2p_types.h>
#include <rt_p2p_api_define.h>
#include <rt_object_api.h>
#include <unistd.h>
#include "NativeCallBack.h"

struct callBack{
    JavaVM *javaVM ;
    jobject jobj;

    jmethodID SearchUIDCallBack;//搜索局域网内的UID设备
    jmethodID ConnectDevCallBack;//连接UID设备
    jmethodID NetworkSpeedCallBack;//视频传输速度
};

struct callBack gCallBack;
ANativeWindow *g_NativeWindow;

int old_speed;

#endif //BARLEY_NATIVE_H
