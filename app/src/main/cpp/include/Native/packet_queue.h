#ifndef WHEAT_PACKETQUEUE_H
#define WHEAT_PACKETQUEUE_H


#include <libavcodec/avcodec.h>
#include <pthread.h>

#define QUEUE_SIZE 100

typedef AVFrame DataType;

typedef struct queue_t{
    DataType dateQueue[QUEUE_SIZE];
    int front;
    int rear;
    int count;
}queue_t;

void init_queue(queue_t* q,pthread_mutex_t *queue_mutex);
int push_queue(queue_t* q, DataType x,pthread_mutex_t *queue_mutex);
int pop_queue(queue_t* q,DataType *temp,pthread_mutex_t *queue_mutex);
void destroy_queue(queue_t* q,pthread_mutex_t *queue_mutex);

#endif //WHEAT_PACKETQUEUE_H
