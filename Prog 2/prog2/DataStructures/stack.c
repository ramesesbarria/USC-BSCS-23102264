#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void stackImplementation() {
    stack mystack;
    mystack.top = -1;
    mystack.capacity = 100;
    mystack.data = (char *)malloc(mystack.capacity * sizeof(char));

    if (mystack.data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int checker = 0;
    while (checker == 0) {
        switch (stackSubMenu()) {
            case 1:
                push(&mystack);
                break;
            case 2:
                pop(&mystack);
                break;
            case 3:
                showStack(&mystack);
                break;
            case 4:
                checker++;
                break;
        }
    }

    free(mystack.data);
    actionChosen();
}
void push(stack *s){
    char input;
    if (s->top == 99){
        printf("Stack overflow\n");
    } else {
        s->top++;
        printf("Enter an input: ");
        scanf(" %c", &input); 
        s->data[s->top] = input;
    }
}

void pop(stack *s){
    if (s->top == -1) {
        printf("Stack empty\n");
    } else {
        char element = s->data[s->top];
        printf("Popped character: %c", s->data[s->top]);
        printf("\n");
        s->top--;
    }
}

void showStack(stack *s){
    if (s->top == -1) {
        printf("Stack empty\n");
    } else {
        printf("The stack currently contains the following: ");
        for (int i = 0; i <= s->top; i++){
            printf("%c ", s->data[i]);
        } printf("\n");
    }
}