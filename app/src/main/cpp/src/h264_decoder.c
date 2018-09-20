//
// Created by yinjian on 2018/3/1.
//

#include <libswscale/swscale.h>
#include <libswresample/swresample.h>
#include <libavutil/imgutils.h>
#include "NativeCaler.h"
#include "h264_decoder.h"

struct SwsContext *swsCtx;

AVCodecContext *CodecCtx=NULL;

AVPacket *packet;

AVFrame *imageFrame;
AVFrame *pFrameRGBA;

ANativeWindow_Buffer windowBuffer;

int old_width;
int old_height;

FILE *fp_yuv;


int VideoDecoder_Open() {
    //初始化FFMPEG
    avcodec_register_all();
    AVCodec *pCodec = avcodec_find_decoder(AV_CODEC_ID_H264);
    if (!pCodec) {
        LOGE("Codec not found\n");
        return -1;
    }
    CodecCtx = avcodec_alloc_context3(pCodec);

    if (!CodecCtx) {
        LOGE("Could not allocate video codec context\n");
        return -1;
    }
    CodecCtx->frame_number = 1;
    CodecCtx->codec_type = AVMEDIA_TYPE_VIDEO;
    /*if (avcodec_parameters_to_context(pCodecCtx,NULL)<0){
        LOGE("Could not open codec\n");
        return -1;
    }*/

    if (avcodec_open2(CodecCtx, pCodec, NULL) < 0) {
        LOGE("Could not open codec\n");
        return -1;
    }

    imageFrame = av_frame_alloc();//内存分配
    pFrameRGBA = av_frame_alloc();// 用于渲染
    if (pFrameRGBA == NULL || imageFrame == NULL) {
        LOGE("Could not allocate video frame.");
        return -1;
    }

    packet = av_packet_alloc();

    fp_yuv = fopen("/storage/6635-3532/a11111a.h264", "wb+");
    if (fp_yuv == NULL) {
        LOGE("Cannot open output file.\n");
        return -1;
    }


    return 0;
}


int initShow(AVCodecContext *pCodecCtx, int window_width, int window_height) {
    enum AVPixelFormat av_pixel_format = AV_PIX_FMT_RGBA;
    // 确定所需的缓冲区大小和分配缓冲区
    int numBytes = av_image_get_buffer_size(av_pixel_format,
                                            pCodecCtx->width, pCodecCtx->height, 1);
    uint8_t *buffer = (uint8_t *) av_malloc(numBytes * sizeof(uint8_t));

    int ret=av_image_fill_arrays(pFrameRGBA->data,
                         pFrameRGBA->linesize,
                         buffer,
                         av_pixel_format,
                         pCodecCtx->width, pCodecCtx->height, 1);
    if (ret < 0){
        LOGE("av_image_fill_arrays init error! %d", ret);
        return -1;
    }

    // 由于解码出来的帧格式不是RGBA的,在渲染之前需要进行格式转换
    swsCtx = (struct SwsContext *) (SwrContext *) sws_getContext(pCodecCtx->width,
                                                                 pCodecCtx->height,
                                                                 pCodecCtx->pix_fmt,
                                                                 window_width, window_height,
                                                                 av_pixel_format,
                                                                 SWS_BILINEAR, NULL, NULL, NULL);
    if (swsCtx == NULL){
        LOGE("sws_getContext init error!");
        return -1;
    }

    // 设置native window的buffer大小,可自动拉伸
    ret=ANativeWindow_setBuffersGeometry(g_NativeWindow, window_width, window_height,
                                     WINDOW_FORMAT_RGBA_8888);
    if (ret != 0){
        LOGE("ANativeWindow_setBuffersGeometry init error! %d", ret);
        return -1;
    }

    return 0;
}

int VideoDecoder_DecFrame(AVFrame *image_Frame, AVCodecContext *pCodecCtx) {
    int ret;
    if (swsCtx == NULL) {
        ret =initShow(pCodecCtx, pCodecCtx->width, pCodecCtx->height);
        if (ret != 0){
            LOGE("initShow() init error! %d", ret);
            return -1;
        }
    }

    //AVFrame转为像素格式RGBA
    int height = sws_scale(swsCtx,
                        (const uint8_t *const *) image_Frame->data,//输入数据
                        image_Frame->linesize,                      //输入画面一行的数据的大小 AVFrame 转换是一行一行转换的
                        0,                                          //输入数据第一列要转码的位置 从0开始
                        pCodecCtx->height,                          //输入画面的高度
                        pFrameRGBA->data,                     //输出数据
                        pFrameRGBA->linesize);                //输出画面一行的数据的大小 AVFrame 转换是一行一行转换的

    uint8_t *dst;
   int dstStride;
    uint8_t *src = NULL;
    size_t srcStride;

    // lock native window buffer
    ANativeWindow_lock(g_NativeWindow, &windowBuffer, 0);

    // 获取stride
    dst = windowBuffer.bits;
    dstStride = windowBuffer.stride * 4;
    src = pFrameRGBA->data[0];
    srcStride = (size_t) pFrameRGBA->linesize[0];

    // 由于window的stride和帧的stride不同,因此需要逐行复制
    int h;
    for (h = 0; h < height; h++) {
        //LOGI("height: %d",h);
        memcpy(dst + h * dstStride, src + h * srcStride, srcStride);
    }

    ANativeWindow_unlockAndPost(g_NativeWindow);
    return 0;
}
//https://blog.csdn.net/qq_41051855/article/details/79051667
int decode_frame(uint8_t *pbuf, int len)//output
{
    if(CodecCtx==NULL){
        VideoDecoder_Open();
    }

    packet->data = pbuf;
    packet->size = len;

    if (fp_yuv == NULL) {
        LOGE("Cannot open output file.\n");
        return -1;
    } else {
        fwrite(pbuf, 1, (size_t) len, fp_yuv);
    }

    int got_picture = 0;
    int ret = avcodec_decode_video2(CodecCtx, imageFrame, &got_picture, packet);

    if ((ret < 0) || (got_picture == 0)) {
        LOGE("Decode Error\n");
        return -1;
    }

    //输入解码器返回解码输出数据
    /*int ret = avcodec_send_packet(CodecCtx, *packet);
    if (ret != 0) {
        if (ret == AVERROR(EAGAIN)) {
            LOGE("avcodec_send_packet EAGAIN ret : %d", ret);
        } else if (ret == AVERROR_EOF) {
            av_packet_unref(packet);//销毁packet
            LOGE("avcodec_send_packet AVERROR_EOF ret : %d", ret);

           // return -1;
        } else if (ret == AVERROR(EINVAL)) {
            LOGE("avcodec_send_packet EINVAL ret : %d", ret);
        } else if (ret == AVERROR(ENOMEM)) {
            LOGE("avcodec_send_packet ENOMEM ret : %d", ret);
        } else if (ret == AVERROR_INVALIDDATA) {

           // return -1;
            LOGE("avcodec_send_packet AVERROR_INVALIDDATA ret : %d", ret);
        }
    }

    //从解码器返回解码输出数据
    ret = avcodec_receive_frame(CodecCtx, imageFrame);
    if (ret != 0) {
        if (ret == AVERROR(EAGAIN)) {
            LOGE("avcodec_receive_frame EAGAIN ret : %d", ret);
        } else if (ret == AVERROR_EOF) {
            LOGE("avcodec_receive_frame AVERROR_EOF ret : %d", ret);
        } else if (ret == AVERROR(EINVAL)) {
            LOGE("avcodec_receive_frame EINVAL ret : %d", ret);
        }
        //return -1;
    }
*/
    VideoDecoder_DecFrame(imageFrame,CodecCtx);

    return 0;
}


void UninitDecoder() {
    avcodec_free_context(&CodecCtx);
    av_frame_free(&imageFrame);
    av_frame_free(&pFrameRGBA);
    av_packet_free(packet);
    fclose(fp_yuv);
}