#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void queueImplementation() {
    queue myQueue;
    myQueue.front = -1;
    myQueue.rear = -1;
    myQueue.capacity = 100;
    myQueue.data = (char *)malloc(myQueue.capacity * sizeof(char));

    if (myQueue.data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int checker = 0;
    while (checker == 0) {
        switch (queueSubMenu()) {
            case 1:
                enqueue(&myQueue);
                break;
            case 2:
                dequeue(&myQueue);
                break;
            case 3:
                showQueue(&myQueue);
                break;
            case 4:
                checker++;
                break;
        }
    }

    free(myQueue.data);
    actionChosen();
}


void enqueue(queue *q) {
    if (q->front == -1) {
            q->front = 0;
    }
    char input;
    if (q->rear == 99) {
        printf("Queue overflow\n");
    } else {
        q->rear++;
        printf("Enter an input: ");
        scanf(" %c", &input);
        q->data[q->rear] = input;
    }
}

void dequeue(queue *q) {
    if (q->front == -1) {
        printf("Queue empty\n");
    } else {
        char element = q->data[q->front];
        printf("Dequeued character: %c", element);
        printf("\n");
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
    }
}

void showQueue(queue *q) {
    if (q->front == -1) {
        printf("Queue empty\n");
    } else {
        printf("The queue currently contains the following: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%c ", q->data[i]);
        }
        printf("\n");
    }
}