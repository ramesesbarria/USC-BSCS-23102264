// top, pop, push, init, isempt, isfull
// cannot be traversed

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} *Stack;

void initStack(Stack* S){
    *S = NULL;
}

bool isEmpty(Stack *S) {
    return (*S == NULL) ? true : false;
}

void push(Stack *S, int data){
    Stack newNode = (Stack) malloc (sizeof(struct node));
    if (newNode != NULL){
        newNode->data = data;
        newNode->next = *S;
        *S = newNode;
    }
}
void pop(Stack *S){
    if (!isEmpty(S)){
        Stack temp = *S;
        *S = temp->next;
        free(temp);
    }
}

void top(Stack *S){
    if (!isEmpty(S)){
        printf("%d", (*S)->data);
    }
}

void displayStack(Stack *S){
    Stack tempStack;
    initStack(&tempStack);

    Stack *trav;
    Stack travT;

    for (trav = S; (*trav) != NULL; trav = &(*trav)->next){
        top(trav);
        push(&tempStack, (*trav)->data);
        pop(&tempStack);
        printf("\n");
    }
    for (travT = tempStack; travT != NULL; travT = travT->next){
        push(S, travT->data);
        pop(&travT);
    }
}


int main() {
    Stack S;
    initStack(&S);
    
    if (isEmpty(&S)) {
        printf("Stack is empty.\n");
    }

    push(&S, 10);
    push(&S, 20);
    push(&S, 30);

    displayStack(&S);

    return 0;
}
