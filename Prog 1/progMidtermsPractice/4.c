#include <stdio.h>

int main(){

    int num, factorial = 1;
    printf("Enter a num: "); //input
    scanf("%d", &num);
    for (int i = 1; i <= num; i++){ //process
        factorial *= i;
    }
    printf("The factorial of %d is %d.", num, factorial); //output

    return 0;
}