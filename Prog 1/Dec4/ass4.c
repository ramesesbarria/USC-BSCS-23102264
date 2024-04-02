#include <stdio.h>

int oddEven(int*);

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int result = oddEven(&num);

    if (result == 0) {
        printf("\nThe given number is even.\n");
    } else {
        printf("\nThe given number is odd.\n");
    }

    return 0;
}

int oddEven(int* num) {
    return *num % 2;
}
