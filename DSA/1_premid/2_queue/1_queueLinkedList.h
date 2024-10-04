#ifndef LINKEDLIST_QUEUE
#define LINKEDLIST_QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
    int data;
    struct node *next;
} *LinkedList;

typedef struct {
    LinkedList front;
    LinkedList rear;
} Queue;

void init(Queue *Q){
    Q->front = NULL;
    Q->rear = NULL;
}
bool isEmpty(Queue *Q){
    return (Q->front == NULL) ? true : false;
}

void enqueue(Queue *Q, int data){
    LinkedList newNode = (LinkedList)malloc(sizeof(struct node));
    if (newNode != NULL){
        newNode->data = data;
        newNode->next = NULL;
        if (isEmpty(Q)){
            Q->front = newNode;
            Q->rear = newNode;
        } else {
            Q->rear->next = newNode;
        }
        Q->rear = newNode;
    }
}

void dequeue(Queue *Q){
    LinkedList temp;
    if (!isEmpty(Q)){
        temp = Q->front;
        Q->front = temp->next;
        free(temp);
        if (isEmpty(Q)){
            Q->rear = NULL;
            Q->front = NULL;
        }
    }
}

void read(Queue Q){
    LinkedList temp;
    for (temp = Q.front; temp != NULL; temp = temp->next){
        printf("%d ", temp->data);
    }
}




#endif