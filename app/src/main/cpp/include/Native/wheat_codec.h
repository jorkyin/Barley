//
// Created by jorkyin on 2017/7/27.
//

#ifndef WHEAT_VIDEOCODEC_H
#define WHEAT_VIDEOCODEC_H

#include <jni.h>
#include <log.h>
#include <stdbool.h>

#include <android/native_window.h>

#include <libswresample/swresample.h>
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/mem.h>
#include <libavutil/frame.h>
#include <libavutil/imgutils.h>
#include <libswscale/swscale.h>

#include "packet_queue.h"
#include "codec_param.h"


int init_audio_decoder();

int getPcm(uint8_t *pcm);

int video_coding(bool *isPlay);

#endif //WHEAT_VIDEOCODEC_H
