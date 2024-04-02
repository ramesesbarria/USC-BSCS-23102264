#include <stdio.h>

#define MAX_SIZE 100

struct myStack {
    int top;
    int size;
    char data[MAX_SIZE];
};

void push(struct myStack *stack, char element) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = element;
}

char pop(struct myStack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    char element = stack->data[stack->top];
    stack->top--;
    return element;
}

int main() {
    int size;
    char element;
    struct myStack stack;
    stack.top = -1;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Size exceeds maximum limit\n");
        return 1;
    }

    stack.size = size;

    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i);
        scanf(" %c", &element);
        push(&stack, element);
    }

    printf("Popping all elements: ");
    while (stack.top >= 0) {
        printf("%c ", pop(&stack));
    }
    printf("\n");

    return 0;
}
