#include <wheat_codec.h>
#include <libavutil/opt.h>
#include<pthread.h>

AVFormatContext *pFormatCtx;
int image_index = -1;
int audio_index = -1;
//https://www.jianshu.com/p/9627ee126328
AVCodecContext *pCodecCtx, *aCodecCtx;

queue_t image_packet_queue, audio_packet_queue;
pthread_mutex_t image_queue_mutex, audio_queue_mutex;

struct SwsContext *sws_ctx;
AVFrame *image_Frame;
AVFrame *image_frame_RGBA;

SwrContext *swrCtx;
AVFrame *audio_frame;
uint8_t *audio_buffer;
int out_channel_nb;
//https://www.jianshu.com/p/b9b80009a26a 用ffmpeg解码H264视频流

int init_audio_decoder() {
    int ret;

    // 对上下文中的视频流进行遍历 Find the first video stream
    int i;
    for (i = 0; i < pFormatCtx->nb_streams; i++) {
        //找到视频流信息后跳出循环
        if (pFormatCtx->streams[i]/*视音频流*/->codecpar->codec_type == AVMEDIA_TYPE_AUDIO//查找音频流标识符
            && audio_index < 0) {
            audio_index = i;
        }
    }

    //若videoIndex还为初值那么说明没有找到视频流
    //LOGI("Find a stream.%d", audio_index);
    if (audio_index < 0) {
        audio_index = -1;
        LOGE("Didn't find a video stream.");
        return -1; // Didn't find a video stream
    }

    //初始化解码器上下文结构体
    aCodecCtx = avcodec_alloc_context3(NULL);
    if (aCodecCtx == NULL) {
        LOGE("Could not allocate codec_param_st->aCodecCtx\n");
        return -1;
    }

    ret = avcodec_parameters_to_context(aCodecCtx, pFormatCtx->streams[audio_index]->codecpar);
    if (ret < 0) {
        LOGE("avcodec_parameters_to_context %d", ret);
        return -1;
    }

    // 声明解码器类型,查找解码器
    AVCodec *aCodec = avcodec_find_decoder(aCodecCtx->codec_id);  //指向AVCodec的指针.查找解码器
    if (aCodec == NULL) {
        LOGE("aCodec not found.\n");
        return -1;
    }

    //打开解码器
    ret = avcodec_open2(aCodecCtx, aCodec, NULL);
    if (ret != 0) {
        LOGE("Could not open aCodec.\n");
        return -1;
    }

    //输出视频信息

   // LOGI("解码器的名称：%s", aCodec->name);
 //   LOGI("支持的采样率：%d", aCodec->supported_samplerates);
  //  LOGI("支持的采样格式：%d", aCodec->sample_fmts);
  //  LOGI("支持的声道数：%d", aCodec->channel_layouts);


    //重采样设置选项-----------------------------------------------------------start
    //输入的采样格式
    enum AVSampleFormat in_sample_fmt = aCodecCtx->sample_fmt;
    //输出的采样格式 16bit PCM
    //enum AVSampleFormat out_sample_fmt =  aCodecCtx->sample_fmt;
    enum AVSampleFormat out_sample_fmt = AV_SAMPLE_FMT_S16;
    //输入的采样率
    int in_sample_rate = aCodecCtx->sample_rate;
    //输出的采样率
    int out_sample_rate = 44100;
    //输入的声道布局
    uint64_t in_ch_layout = aCodecCtx->channel_layout;
    //输出的声道布局
    uint64_t out_ch_layout = AV_CH_LAYOUT_STEREO;

   // LOGI("in_sample_fmt  ret:%d", in_sample_fmt);
   // LOGI("out_sample_fmt  ret:%d", out_sample_fmt);
  //  LOGI("in_sample_rate  ret:%d", in_sample_rate);
  //  LOGI("out_sample_rate  ret:%d", out_sample_rate);
  //  LOGI("in_ch_layout  ret:%d", in_ch_layout);
   // LOGI("out_ch_layout  ret:%d", out_ch_layout);

    //frame->16bit 44100 PCM 统一音频采样格式与采样率
    swrCtx = swr_alloc();
    av_opt_set_sample_fmt(swrCtx, "in_sample_fmt", in_sample_fmt, 0);
    av_opt_set_sample_fmt(swrCtx, "out_sample_fmt", out_sample_fmt, 0);
    av_opt_set_int(swrCtx, "in_sample_rate", in_sample_rate, 0);
    av_opt_set_int(swrCtx, "out_sample_rate", out_sample_rate, 0);
    av_opt_set_channel_layout(swrCtx, "in_channel_layout", in_ch_layout, 0);
    av_opt_set_channel_layout(swrCtx, "out_channel_layout", out_ch_layout, 0);
    swr_init(swrCtx);
    //重采样设置选项-----------------------------------------------------------end

    //获取输出的声道个数
    out_channel_nb = av_get_channel_layout_nb_channels(out_ch_layout);
    //   LOGI("out_channel_nb  ret:%d", out_channel_nb);

    audio_buffer = (uint8_t *) av_malloc(44100 * 2);
    audio_frame = av_frame_alloc();

    init_queue(&audio_packet_queue, &audio_queue_mutex);

    return 0;
}


int video_coding(bool *isPlay) {
    // LOGI("video_coding");
    /*int ret;
    //帧数据
    AVPacket *packet = av_malloc(sizeof(AVPacket));
    AVFrame *imageFrame = av_frame_alloc();
    AVFrame *audioFrame = av_frame_alloc();
    while (*isPlay) {
        // LOGE("isPlay  : %d", *isPlay);
        if (av_read_frame(pFormatCtx, packet) < 0) {
            LOGE("av_read_frame Error");
            break;
        }
        if (packet->stream_index == image_index) {// 视频流
            // LOGE("image_index  %d",packet->size);

            //LOGI("image_packet->size: %d",packet->size);
            //输入解码器返回解码输出数据
            ret = avcodec_send_packet(pCodecCtx, packet);
            if (ret != 0) {
                LOGE("avcodec_send_packet ret : %d", ret);
                if (ret == AVERROR(EAGAIN)) {
                    LOGE("EAGAIN ret : %d", ret);
                } else if (ret == AVERROR_EOF) {
                    LOGE("AVERROR_EOF ret : %d", ret);
                } else if (ret == AVERROR(EINVAL)) {
                    LOGE("EINVAL ret : %d", ret);
                } else if (ret == AVERROR(ENOMEM)) {

                    LOGE("ENOMEM ret : %d", ret);
                } else if (ret == AVERROR_INVALIDDATA) {

                    continue;
                    LOGE("AVERROR_INVALIDDATA ret : %d", ret);
                }
            }

            //从解码器返回解码输出数据
            ret = avcodec_receive_frame(pCodecCtx, imageFrame);
            if (ret != 0) {
                LOGE("avcodec_receive_frame ret : %d", ret);

                if (ret == AVERROR(EAGAIN)) {
                    LOGE("EAGAIN ret : %d", ret);

                } else if (ret == AVERROR_EOF) {
                    LOGE("AVERROR_EOF ret : %d", ret);
                } else if (ret == AVERROR(EINVAL)) {
                    LOGE("EINVAL ret : %d", ret);
                }
                //av_frame_free(&image_frame);
                continue;
            }

            while (true) {
                if (push_queue(&image_packet_queue, *imageFrame, &image_queue_mutex) == 0) {//写入队列
                    break;
                }
            }
        } else if (packet->stream_index == audio_index) {// 音频流
            //LOGI("audio_index packet size ret : %d", packet->size);
            // LOGI("audio_index PTS ret : %d", packet->pts);
            //输入解码器返回解码输出数据
            ret = avcodec_send_packet(aCodecCtx, packet);
            if (ret != 0) {
                LOGE("avcodec_send_packet ret : %d", ret);
                if (ret == AVERROR(EAGAIN)) {
                    LOGE("EAGAIN ret : %d", ret);
                } else if (ret == AVERROR_EOF) {
                    LOGE("AVERROR_EOF ret : %d", ret);
                } else if (ret == AVERROR(EINVAL)) {
                    LOGE("EINVAL ret : %d", ret);
                } else if (ret == AVERROR(ENOMEM)) {
                    LOGE("ENOMEM ret : %d", ret);
                } else if (ret == AVERROR_INVALIDDATA) {
                    continue;
                    LOGE("AVERROR_INVALIDDATA ret : %d", ret);
                }
                //continue;
            }
            //从解码器返回解码输出数据
            ret = avcodec_receive_frame(aCodecCtx, audioFrame);
            if (ret != 0) {
                LOGE("avcodec_receive_frame ret : %d", ret);

                if (ret == AVERROR(EAGAIN)) {
                    LOGE("EAGAIN ret : %d", ret);

                } else if (ret == AVERROR_EOF) {
                    LOGE("AVERROR_EOF ret : %d", ret);
                } else if (ret == AVERROR(EINVAL)) {
                    LOGE("EINVAL ret : %d", ret);
                }
                //av_frame_free(&image_frame);
                continue;
            }
            LOGI("audioFrame->nb_samples  %d", audioFrame->nb_samples);
            while (true) {
                if (push_queue(&audio_packet_queue, *audioFrame, &audio_queue_mutex) == 0) { //写入队列
                    break;
                }
            }
        }
        av_packet_unref(packet);//销毁packet
    }*/
    return 0;
}

int getPcm(uint8_t *pcm) {

    while (true) {
        if (pop_queue(&audio_packet_queue, audio_frame, &audio_queue_mutex) == 0) {
            break;
        }
    }

    /*swr_convert(swrCtx, &audio_buffer, 44100 * 2, (const uint8_t **) audio_frame->data,
                audio_frame->nb_samples);

    int size = av_samples_get_buffer_size(NULL, out_channel_nb, audio_frame->nb_samples,
                                          AV_SAMPLE_FMT_S16, 1);*/
    LOGI("audio_frame->nb_samples  %d", audio_frame->nb_samples);
    swr_convert(swrCtx, &audio_buffer, 44100 * 2, (const uint8_t **) audio_frame->data,
                audio_frame->nb_samples);

    int size = av_samples_get_buffer_size(NULL, out_channel_nb, audio_frame->nb_samples,
                                          AV_SAMPLE_FMT_S16, 1);
    //LOGI("audio_frame size %d", size);
    memcpy(pcm, audio_buffer, (size_t) size);

    return size;
}
