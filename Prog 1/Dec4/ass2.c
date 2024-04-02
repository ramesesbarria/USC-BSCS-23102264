#include <stdio.h>

void converter(int*);

int main() {
    int num;

    printf("Enter a positive or negative integer: ");
    scanf("%d", &num);
    printf("You entered %d\n", num);

    converter(&num);

    printf("The opposite value is %d", num);

    return 0;
}

void converter(int* num) {
    (*num) *= -1;
}
