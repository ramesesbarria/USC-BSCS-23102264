#ifndef CURSORBASED_STACK
#define CURSORBASED_STACK

#include <stdio.h>
#define MAX 10

typedef struct {
    int num;
    int link;
} Node;

typedef struct {
    Node nodes[MAX];
    int avail;
} VirtualHeap;

typedef int Stack;

void init(Stack *S, VirtualHeap *VH){
    for (int i = 0; i < MAX - 1; i++){
        VH->nodes[i].link = i + 1;
    }
    VH->nodes[MAX - 1].link = -1;
    VH->avail = 0;
    *S = -1;
}

int mallocVH(VirtualHeap *VH){
    int temp = VH->avail;
    if (temp != -1){
       VH->avail = VH->nodes[VH->avail].link; 
    } 
    return temp;
}

void freeVH(VirtualHeap *VH, int index){
    if (index >= 0 && index < MAX){
        VH->nodes[index].link = VH->avail;
        VH->avail = index;
    }
}

void pop(Stack *S, VirtualHeap *VH){
    if (*S != -1){
        Stack temp = *S;
        *S = VH->nodes[*S].link;
        freeVH(VH, temp);
    }
}

void push(Stack *S, VirtualHeap *VH, int data){
    Stack index = mallocVH(VH);
    if (index != -1){
        VH->nodes[index].num = data;
        VH->nodes[index].link = *S;
        *S = index;
    }
}
void top(Stack *S, VirtualHeap *VH){
    if (*S != -1){
        printf("%d\n", VH->nodes[*S].num);
    }
}
void read(Stack *S, VirtualHeap *VH){
    Stack temp = *S;
    VirtualHeap VHTemp = *VH;
    while(temp != -1){
        top(&temp, &VHTemp);
        pop(&temp, &VHTemp);
    }
}

#endif