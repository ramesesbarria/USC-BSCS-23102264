#ifndef CURSORBASED
#define CURSORBASED

#include <stdio.h>
#define MAX 7

typedef struct {
    char elem;
    int link;
} Nodetype;

typedef struct {
    Nodetype nodes[MAX];
    int avail;
} VirtualHeap;

typedef int List;

void initLinkAndVH(List *L, VirtualHeap *VH){
    for (int i = 1; i < MAX; i++){
        VH->nodes[i - 1].link = i;
    }
    VH->nodes[MAX - 1].link = -1;
    VH->avail = 0;
    *L = -1;
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

void insertFirst(List *L, VirtualHeap *VH, char elem){
    int avail = mallocVH(VH);
    if (avail != -1){
        VH->nodes[avail].elem = elem;
        VH->nodes[avail].link = *L;
        *L = avail;
    }
}

void insertLast(List *L, VirtualHeap *VH, char elem){
    int avail = mallocVH(VH);
    if (avail != -1){
        List *curr;
        for (curr = L; (*curr) != -1; curr = &(VH->nodes[*curr].link)){}
        VH->nodes[avail].elem = elem;
        VH->nodes[avail].link = -1;
        *curr = avail;
    }
}

void printList(List *L, VirtualHeap *VH){
    List *trav;
    for (trav = L; (*trav) != -1; trav = &(VH->nodes[*trav].link)){
        printf("%c%s", VH->nodes[*trav].elem, (VH->nodes[*trav].link != -1) ? ", ": ".\n");
    }
}

#endif
