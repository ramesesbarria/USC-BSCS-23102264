#include "6_cursorBased.h"
#include <stdio.h>


int main(){

    VirtualHeap VH;
    List L;

    initLinkAndVH(&L, &VH);

    char name[5] = {'A', 'm', 'o', 'r', 'A'};
    for (int i = 0; i < 5; i++){
        insertLast(&L, &VH, name[i]);
    }
    printList(&L, &VH);

}