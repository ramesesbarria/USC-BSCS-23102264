#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    int front;
    int rear;
    char *data;
    int capacity;
} queue;

void queueImplementation();
void enqueue(queue *q);
void dequeue(queue *q);
void showQueue(queue *q);

#endif
