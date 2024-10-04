#ifndef LINKEDLIST_QUEUE
#define LINKEDLIST_QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int data;
} Element;

typedef struct {
    Element elem;
    int next;
} Node;

typedef struct {
    Node nodes[MAX];
    int avail;
} VirtualHeap;

typedef int Queue;

typedef struct {
    Queue front;
    Queue back;
} Queues;

void init(Queues *Q, VirtualHeap *VH){
    for (int i = 0; i < MAX - 1; i++){
        VH->nodes[i].next = i + 1;
    }
    VH->nodes[MAX - 1].next = -1;
    VH->avail = 0;
    Q->front = -1;
    Q->back = -1;
}

bool isEmpty(Queues *Q, VirtualHeap *VH){
    return (Q->front == -1) ? true : false;
}

int mallocVH(VirtualHeap *VH){
    int temp = VH->avail;
    if (temp != -1){
       VH->avail = VH->nodes[VH->avail].next; 
    } 
    return temp;
}

void freeVH(VirtualHeap *VH, int index){
    if (index >= 0 && index < MAX){
        VH->nodes[index].next = VH->avail;
        VH->avail = index;
    }
}

void enqueue(Queues *Q, VirtualHeap *VH, int data){
    Queue index = mallocVH(VH);
    if (index != -1){
        VH->nodes[index].elem.data = data;
        VH->nodes[index].next = -1;
        if (isEmpty(Q, VH)){
            Q->front = index;
        } else {
            VH->nodes[Q->back].next = index;
        }
        Q->back = index;
    }
}

void dequeue(Queues *Q, VirtualHeap *VH){
    Queue temp;
    if (!isEmpty(Q, VH)){
        temp = Q->front;
        Q->front = VH->nodes[Q->front].next;
        freeVH(VH, temp);
        if (isEmpty(Q, VH)){
            Q->back = -1;
            Q->front = -1;
        }
    }
}

void read (Queues *Q, VirtualHeap *VH){
    Queue temp;
    for (temp = Q->front; temp != -1; temp = VH->nodes[temp].next){
        printf("%d ", VH->nodes[temp].elem.data);
    }
}

#endif