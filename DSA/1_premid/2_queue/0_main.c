#include "2_queueCursorBased.h"
#include <stdio.h>


int main(){
    Queues Q;
    VirtualHeap VH;

    init(&Q, &VH);
    enqueue(&Q, &VH, 1);
    enqueue(&Q, &VH, 2);
    enqueue(&Q, &VH, 3);
    read(&Q, &VH);
    dequeue(&Q, &VH);
    read(&Q, &VH);    

  
}