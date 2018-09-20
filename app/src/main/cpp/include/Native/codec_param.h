//
// Created by yinjian on 2017/10/18.
//

#ifndef NDKSDL2_0_CODEC_DATE_H
#define NDKSDL2_0_CODEC_DATE_H

#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include "packet_queue.h"
#include <stdbool.h>

typedef struct codec_st{
    int index;
    AVCodecContext *avCodecCtx;//初始化解码器上下文结构体

    struct queue_t *packetQueue;
    pthread_mutex_t queueMutex;
}codec_st;


#endif //NDKSDL2_0_CODEC_DATE_H
