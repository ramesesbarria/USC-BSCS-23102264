#ifndef LINKEDLIST_STACK
#define LINKEDLIST_STACK

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int num;
} Data;
typedef struct node{
    Data data;
    struct node *next;
} *Stack;

void init(Stack *S){
    *S = NULL;
}
void pop(Stack *S){
    if (*S != NULL){
        Stack temp = *S;
        *S = temp->next;
        free(temp);
    }
}
void push(Stack *S, int data){
    Stack temp = (Stack) malloc (sizeof(struct node));
    if (temp != NULL){
        temp->data.num = data;
        temp->next = *S;
        *S = temp;
    }
}
void top(Stack S){
    if (S != NULL){
        printf("%d", S->data.num);
    }
}
void read(Stack S){
    Stack temp = S;
    while (temp != NULL){
        top(temp);
        pop(&temp);
    }
}

#endif