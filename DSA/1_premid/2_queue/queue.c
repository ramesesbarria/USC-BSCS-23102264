// Front, Dequeue, Enqueue, and other utility functions such as initQueue, isEmpty, and isFull

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
} *LL;

typedef struct{
    LL front;
    LL rear;
} Queue;

void init(Queue* Q){
    Q->front = NULL;
    Q->rear = NULL;
}

bool isEmpty(Queue Q){
    return (Q.front == NULL) ? true : false;
}

int front(Queue Q) {
    return (!isEmpty(Q)) ? Q.front->data : -1;
}

void dequeue(Queue *Q){
    if (!isEmpty(*Q)){
        LL temp = Q->front;  
        Q->front = Q->front->next;
        if(isEmpty(*Q)){
            Q->rear = NULL;
        }
        free(temp);
    }
}
void enqueue(Queue *Q, int data){
    LL temp = (LL)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = data;
        temp->next = NULL;
        if(isEmpty(*Q)){
            Q->front = temp;
        } else {
            Q->rear->next = temp;
        }
        Q->rear = temp;
    }
}

void read(Queue *Q) {
    Queue temp;
    init(&temp);
    while (!isEmpty(*Q)) {
        int value = front(*Q);
        printf("%d", value); // Output the value
        enqueue(&temp, value);
        dequeue(Q);
    }
    *Q = temp;
    printf("\n");  // Newline for better output formatting
}


int main(){
    Queue Q;
    init(&Q);
    enqueue(&Q, 2);
    enqueue(&Q, 1);
    enqueue(&Q, 3);
    read(&Q);
    enqueue(&Q, 3);
    read(&Q);

}

