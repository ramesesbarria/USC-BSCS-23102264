#include <stdio.h>
int main(){

    int sizeOfBox;

    printf("Enter a number from 5 - 15 and I will print a box with an X that corresponds to that size: ");
    while(scanf("%d", &sizeOfBox) != 1 || sizeOfBox > 15 || sizeOfBox < 5){
        while(getchar() != '\n');
        printf("Invalid number, please re-enter: ");
    }

    printf("\n");

    for (int i = 1; i <= sizeOfBox; i++){
        for (int j = 1; j <= sizeOfBox; j++){
            if (j == i || j == sizeOfBox - i + 1){
                printf("X ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}