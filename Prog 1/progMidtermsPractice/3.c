#include <stdio.h>

int main(){

    int year;
    printf("Enter the year: ");

    while(scanf("%d", &year) != 1 || year > 9999 || year < 1000){ //input
        while(getchar() != '\n');
        printf("Invalid year, re-input: ");
    }

    if (year % 4 == 0){ //process
        printf("%d is a leap year.", year); //outputs
    } else {
        printf("%d is a normal year.", year); //outputs
    }

    return 0;
}