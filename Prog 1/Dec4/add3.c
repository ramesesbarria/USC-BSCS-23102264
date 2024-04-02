#include <stdio.h>

void oddEven(int*);

int main(){

    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    oddEven(&num);

    return 0;

}

void oddEven(int* num){

    if (*num % 2 == 0){
        printf("\nThe given number is even.\n");
    } else {
        printf("\nThe given number is odd.\n");
    }

}