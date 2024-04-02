#include <stdio.h>
int main(){

    int X, Y;
    float ave;

    printf("Enter your first number: ");
    scanf("%d", &X);
    printf("Enter your second number: ");
    scanf("%d", &Y);

    ave = ((float) X + (float) Y)/2;

    if (((X + Y)/2) % 2 == 0){
        printf("The average of %d and %d is %.2f, which is even.", X, Y, ave);
    } else {
        printf("The average of %d and %d is %.2f, which is odd", X, Y, ave);
    }

    return 0;

}