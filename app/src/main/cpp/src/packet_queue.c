#include "packet_queue.h"
#include <log.h>
#include <stdbool.h>

void init_queue(queue_t *q, pthread_mutex_t *queue_mutex) {
    int ret;
    ret = pthread_mutex_init(queue_mutex, NULL);
    if (ret != 0) {
        LOGI("Mutex init failed.\n");
        exit(EXIT_FAILURE);
    }
    memset(q->dateQueue, 0, QUEUE_SIZE * sizeof(DataType));
    q->front = q->rear = 0;
    q->count = 0;
}

bool is_empty_queue(queue_t *q) {
    if (q->count > 0) { return false; }
    return true;
}

bool is_full_queue(queue_t *q) {
    if (q->count < QUEUE_SIZE) { return false; }
    return true;
}

int push_queue(queue_t *q, DataType x, pthread_mutex_t *queue_mutex) {
    pthread_mutex_lock(queue_mutex);
    if (is_full_queue(q)) {
        //LOGE("queue overflow.\n");
        pthread_mutex_unlock(queue_mutex);
        return -1;
    }

    q->count++;
    q->dateQueue[q->rear] = x;
    //LOGI("q->front=%d,q->rear=%d,q->count=%d ", q->front, q->rear, q->count);
    q->rear = (q->rear + 1) % QUEUE_SIZE;


    pthread_mutex_unlock(queue_mutex);
    return 0;
}

int pop_queue(queue_t *q, DataType *temp, pthread_mutex_t *queue_mutex) {
    pthread_mutex_lock(queue_mutex);
    if (is_empty_queue(q)) {
        //LOGE("queue empty.\n");
        pthread_mutex_unlock(queue_mutex);
        return -1;
    }

    memcpy(temp, &(q->dateQueue[q->front]), sizeof(q->dateQueue[q->front]));
    //LOGI("q->front=%d,q->rear=%d,q->count=%d ", q->front, q->rear, q->count);
    q->count--;
    q->front = (q->front + 1) % QUEUE_SIZE;

    pthread_mutex_unlock(queue_mutex);

    return 0;
}

void destroy_queue(queue_t *q, pthread_mutex_t *queue_mutex) {
    pthread_mutex_destroy(queue_mutex);
    return;
}