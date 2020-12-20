
#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct QueueType {
    int queue[MAX_QUEUE_SIZE];
    int front,rear;
}QueueType;

void queue_init(QueueType *q) {
    q->front = q->rear = 0;
}

int queue_is_empty(QueueType *q) {
    return (q->front == q->rear);
}

int queue_is_full(QueueType *q) {
    return ((q->rear)%MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, int item) {
    if(is_full(q)) {
        printf("큐가 가득 찼습니다.");
        exit(1);
    }
    q->rear = (q->rear)%MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

int dequeue(QueueType *q) {
    if(is_empty(q)) {
        printf("큐가 비어 있음");
        exit(1);
    }
    q->front = (q->front+1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}


#endif
