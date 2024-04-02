// 1. Write a function named addNum() 
// in C that accepts 2 integer pointers and 
// adds the value of the 2 numbers pointed to 
// by the pointers and returns the sum
// to the calling function 

#include <stdio.h>

int addNum(int*, int*);

int main(){

    int num1, num2;

    printf("Number 1: ");
    scanf("%d", &num1);

    printf("Number 2: ");
    scanf("%d", &num2);

    int* aNum1 = &num1;
    int* aNum2 = &num1;

    int sum = addNum(aNum1, aNum2);

    printf("The sum of %d and %d is %d", *aNum1, *aNum2, sum);
    
    return 0;

}

int addNum(int* aNum1, int* aNum2){

    int sum = *aNum1 + *aNum2;
    return sum;
}