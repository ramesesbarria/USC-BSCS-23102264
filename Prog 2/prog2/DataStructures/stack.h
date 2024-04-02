#ifndef STACK_H
#define STACK_H

typedef struct {
    int top;
    char *data;
    int capacity;
} stack;

void stackImplementation();
void push(stack *s);
void pop(stack *s);
void showStack(stack *s);

#endif
