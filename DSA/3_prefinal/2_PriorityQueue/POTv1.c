#include <stdio.h>
#include <stdlib.h>
#define MAX 15

typedef struct {
    int elements[MAX];
    int lastIndex;
} POT;

void initPOT(POT* pq){
    pq->lastIndex = -1;
}
void insertPOT(POT* pq, int data) {
    if (pq->lastIndex < MAX) {
        int child = ++pq->lastIndex;
        int parent = (child-1)/2;

        while (child > 0 && pq->elements[parent] > data){
            pq->elements[child] = pq->elements[parent];
            child = parent;
            parent = (child - 1)/2;
        }
        pq->elements[child] = data;
    }
}

void populatePOT(POT* pq, int arr[], int size){
    for (int i = 0; i < size; i++){
        insertPOT(pq, arr[i]);
    }
}

int deleteMIN(POT* pq){
    int min = -1; 
    if(pq->lastIndex != -1){
        min = pq->elements[0]; // root node
        int repl = pq->elements[pq->lastIndex--]; // right most node to replace root node

        int parentIDX = 0;
        int LCIDX = 1;
        int RCIDX = 2;

        int childIDX = pq->elements[LCIDX] < pq->elements[RCIDX] ? LCIDX : RCIDX;

        while(childIDX <= pq->lastIndex && pq->elements[childIDX] < repl){ // to order nodes for POT property
            pq->elements[parentIDX] = pq->elements[childIDX];
            parentIDX = childIDX;
            LCIDX = parentIDX * 2 + 1;
            RCIDX = LCIDX + 1;
            childIDX = pq->elements[LCIDX] < pq->elements[RCIDX] ? LCIDX : RCIDX;
        }
        pq->elements[parentIDX] = repl;
    }
    return min;
}

    void displayTree(POT* pq) {
        if (pq->lastIndex == -1) {
            printf("The priority queue is empty.\n");
        } else {
            printf("Priority Queue elements:\n");
            for (int i = 0; i <= pq->lastIndex; i++) {
                printf("%d ", pq->elements[i]);
            }
            printf("\n");
        }
    }


    int main() {
        POT pq;
        initPOT(&pq);

        int values[] = {3, 4, 9, 8, 5, 9, 10, 10, 18, 9, 6};
        int size = sizeof(values) / sizeof(values[0]);

        populatePOT(&pq, values, size);
        displayTree(&pq);

        printf("Deleting minimum elements:\n");
        while (pq.lastIndex != -1) {
            printf("Deleted: %d\n", deleteMIN(&pq));
            displayTree(&pq);
        }

        return 0;
    }