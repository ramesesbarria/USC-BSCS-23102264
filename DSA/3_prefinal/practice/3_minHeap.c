/* 
- the parent node is at index child-1/2 
- the left child is parent*2+1
- the right child is parent*2+2
*/
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
    if(t->lastIndex < MAX - 1){
       int child = ++t->lastIndex;
       int parent = (child - 1) / 2;
       while (child >= 0 && t->elements[parent] > elem){
            t->elements[child] = t->elements[parent];
            child = parent;
            parent = (child - 1) / 2;
       }
       t->elements[child] = elem;

    }
}

int delete(minHeap* t){
    int deletedMin = t->elements[0];
    if (t->lastIndex >= 0){
        int replacement = t->elements[t->lastIndex--];

        int parent = 0;
        int LC = 1;
        int RC = 2;
        int child = t->elements[LC] < t->elements[RC] ? LC : RC;

        while (child <= t->lastIndex && t->elements[child] < replacement){
            t->elements[parent] = t->elements[child];
            parent = child;
            LC = parent * 2 + 1;
            RC = parent * 2 + 2;
            child = t->elements[LC] < t->elements[RC] ? LC : RC;
        }
        t->elements[parent] = replacement;
    
    }
    return deletedMin;
}

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
    int temp = t->lastIndex;
    for(i = t->lastIndex; i > 0; i--){
        int temp = t->elements[0];
        t->elements[0] = t->elements[i];
        t->elements[i] = temp;
        t->lastIndex--;
        heapifySubtree(t, 0);
    }
    t->lastIndex = temp;
}

void display(minHeap t){
    for (int i = 0; i <= t.lastIndex; i++) {
        printf("%d ", t.elements[i]);
    }
    printf("\n");
}

int main() {
    minHeap heap;
    init(&heap);

    insert(&heap, 10);
    insert(&heap, 4);
    insert(&heap, 9);
    insert(&heap, 1);
    insert(&heap, 7);
    insert(&heap, 5);
    insert(&heap, 3);

    printf("Heap elements after insertion: ");
    display(heap);

    printf("Deleted min element: %d\n", delete(&heap));

    printf("Heap elements after deletion: ");
    display(heap);

    heapsortMin(&heap);
    printf("Heap elements after heapsort: ");
    display(heap);

    return 0;
}