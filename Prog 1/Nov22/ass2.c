// 2. Write a function named maxNum() 
// in C that accepts 2 integer pointers 
// and find the maximum number between two numbers 
// using a pointer and returns the max num
// to the calling function

#include <stdio.h>

int maxNum(int *ptr1, int *ptr2) {

    int max = (*ptr1 > *ptr2) ? *ptr1 : *ptr2;

    return max;
}

int main() {
    int num1, num2;

    printf("Number 1: ");
    scanf("%d", &num1);

    printf("Number 2: ");
    scanf("%d", &num2);

    int *ptrNum1 = &num1;
    int *ptrNum2 = &num2;

    int result = maxNum(ptrNum1, ptrNum2);
    printf("Maximum Number: %d\n", result);

    return 0;
}


