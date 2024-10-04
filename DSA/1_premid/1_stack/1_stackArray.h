#ifndef ARRAY_STACK
#define ARRAY_STACK

#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int num;
} Data;
typedef struct {
    Data data[MAX];
    int top;
} Stack;

bool isEmpty(Stack S){
    return (S.top == -1) ? true : false; }
bool isFull(Stack S){
    return (S.top == MAX - 1) ? true : false;
}
void init(Stack *S){
    S->top = -1;
}
void pop(Stack *S){
    if (!isEmpty(*S)){
        S->top--;
    }
}
void push(Stack *S, int data){
    if (!isFull(*S)){
        S->data[++S->top].num = data;
    }
}
void top(Stack S){
    if (!isEmpty(S)){
        printf("%d", S.data[S.top].num);
    }
}
void read(Stack S){
    Stack temp = S;
    while(temp.top != -1){
        top(temp);
        pop(&temp);
    }
}
#endif
