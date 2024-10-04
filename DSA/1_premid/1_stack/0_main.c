#include "3_cursorBased.h"
#include <stdio.h>


int main(){
   Stack S;
   VirtualHeap VH;
   init(&S, &VH);
   push(&S, &VH, 1);
   push(&S, &VH, 2);
   push(&S, &VH, 3);
   push(&S, &VH, 4);
   read(&S, &VH);
   pop(&S, &VH);
   read(&S, &VH);
}