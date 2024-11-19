

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int elements[MAX];
    int lastIndex;
}minHeap;

void init(minHeap* t){
    t->lastIndex = - 1;
}

void insert(minHeap* t, int elem){
    if (t->lastIndex < MAX - 1){
        // if there's space, add element to right most available index
        t->elements[++t->lastIndex] = elem;
        // place index in the appropriate place according to minheap property
        int index;
        for (index = t->lastIndex; index >= 0 && t->elements[index] < t->elements[(index-1)/2]; index = (index - 1)/2){
            int temp = t->elements[index]; // to hold the to be inserted elem
            t->elements[index] = t->elements[(index - 1)/2]; // place parent at the index of to be inserted elem
            t->elements[(index - 1)/2] = temp; // placed to be inserted elem at previous place of parent (swapping)
        }
    }
}

int deleteMin(minHeap* t){ // without heapify
    int min = -1;
    if (t->lastIndex >= 0){
        min = t->elements[0];
        int repl = t->elements[t->lastIndex--];

        // algorithm to replace root node with the proper element that respect minheap property
        int parent = 0; 
        int LC = 1;
        int RC = 2;

        int child = t->elements[LC] < t->elements[RC] ? LC : RC;

        while (child <= t->lastIndex && t->elements[child] < repl){
            t->elements[parent] = t->elements[child];
            parent = child;
            LC = parent * 2 + 1;
            RC = parent * 2 + 2;
            child = t->elements[LC] < t->elements[RC] ? LC : RC;
        }
        t->elements[parent] = repl;   
    }
    return min;
}

void display(minHeap t){
    for (int i = 0; i <= t.lastIndex; i++) {
        printf("%d ", t.elements[i]);
    }
    printf("\n");
}

// heapify based functions

void heapifySubtree(minHeap* t, int parent){
    int smallestNode = parent;
    int LC = parent * 2 + 1;
    int RC = parent * 2 + 2;

    if (LC <= t->lastIndex && t->elements[LC] < t->elements[smallestNode]){
        smallestNode = LC;
    }

    if (RC <= t->lastIndex && t->elements[RC] < t->elements[smallestNode]){
        smallestNode = RC;
    }

    if (smallestNode != parent){
        int temp = t->elements[smallestNode];
        t->elements[smallestNode] = t->elements[parent];
        t->elements[parent] = temp;
        heapifySubtree(t, smallestNode);
    }
}

void heapifyAll(minHeap* t){
    int lastIndex = t->lastIndex;
    int i;
    for (i = (lastIndex-1)/2; i > 0; i--){
        heapifySubtree(t, i);
    }
}

void heapsortMin(minHeap* t){
    heapifyAll(t);
    int i;
    for(i = t->lastIndex; i > 0; i--){
        int temp = t->elements[0];
        t->elements[0] = t->elements[i];
        t->elements[i] = temp;
        t->lastIndex--;
        heapifySubtree(t, 0);
    }
}