//
// Created by yinjian on 2018/3/1.
//

#ifndef BARLEY_H264_DECODER_H
#define BARLEY_H264_DECODER_H
#include <rt_p2p_types.h>
#include <stdbool.h>
#include <log.h>
#include <stdint.h>

#include <android/native_window.h>
#include <libavutil/frame.h>
#include <libavcodec/avcodec.h>

//清理解码器申请的资源
void UninitDecoder(void);

int VideoDecoder_Open();
int decode_frame(uint8_t *pbuf, int len);
#endif //BARLEY_H264_DECODER_H
