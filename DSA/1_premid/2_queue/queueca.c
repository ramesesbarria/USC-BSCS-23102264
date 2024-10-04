#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 8
#define nELEM (MAX - 1)

typedef struct {
    int data;
} Elem;

typedef struct {
    Elem elements[MAX];
    int front;
    int rear;
} QueueCA;

void init(QueueCA* Q){
    Q->front = 0;
    Q->rear = nELEM;
}

bool isEmpty(QueueCA Q){
    return ((Q.rear + 1) % MAX == Q.front) ? true : false;
}

bool isFull(QueueCA Q){
    return ((Q.rear + 2) % MAX == Q.front) ? true : false;
}

void enqueue(QueueCA *Q, int data){
    if(!isFull(*Q)){
        Q->rear = (Q->rear + 1) % MAX;;
        Q->elements[Q->rear].data = data;
    }
}

void dequeue(QueueCA *Q){
    if(!isEmpty(*Q)){
        Q->front = (Q->front + 1) % MAX;
    }
}

int front(QueueCA Q){
    return (!isEmpty(Q)) ? Q.elements[Q.front].data : -1;
}

void read(QueueCA Q){
    printf("Queue: ");
    int i = Q.front;
    while(i <= Q.rear){
        printf("%d ", Q.elements[i].data);
        i = i + 1 % MAX;
    }
}

int main() {
    QueueCA Q;
    init(&Q);
    
    enqueue(&Q, 10);
    enqueue(&Q, 20);
    enqueue(&Q, 30);
    enqueue(&Q, 40);

    read(Q); // Should print: 10 20 30 40

    dequeue(&Q);
    read(Q); // Should print: 20 30 40

    return 0;
}
