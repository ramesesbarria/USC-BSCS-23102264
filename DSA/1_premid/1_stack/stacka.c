#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int data;
} Element;

typedef struct {
    Element Elements[MAX];
    int index; //index of stack top
} Stack;

// Top, Pop, Push, and other utility functions such as initStack, isEmpty, and isFull
void init(Stack *S);
void read(Stack S);
bool isEmpty(Stack S);
bool isFull(Stack S);
int top(Stack S);
void pop(Stack *S);
void push(Stack *S, int data);


int main() {
    Stack S;
        
    init(&S);
    push(&S, 1);
    top(S);
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    read(S);


    return 0;
}

void init(Stack *S){
    S->index = -1;
}

void read(Stack S){
    if(!isEmpty(S)){
        Stack temp;
        init(&temp);
        while(S.index != -1){
            push(&temp, top(S));
            pop(&S);
        }
        S = temp;
    }
    
}
 
bool isEmpty(Stack S){
    return (S.index == -1) ? true : false;
}
bool isFull(Stack S){
    return (S.index == MAX - 1) ? true : false;
}

int top(Stack S){
    printf("%d", S.Elements[S.index].data);
    return (!isEmpty(S)) ? S.Elements[S.index].data : -1;
}
void pop(Stack *S){
    if(!isEmpty(*S)){
        S->index--;
    }
}
void push(Stack *S, int data){
    if(!isFull(*S)){
        S->Elements[++S->index].data = data;
    }
}