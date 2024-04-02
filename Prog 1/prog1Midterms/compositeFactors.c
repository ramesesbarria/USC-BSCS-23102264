#include <stdio.h>

int isPrime(int amor);

int main(){

    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    for (int i = 1; i <= number; i++){
        if (number % i == 0){ //takes the factors of int number
            if (isPrime(i)){ //isPrime checks if factor is prime number
                printf("%d ", i);
            } else {
                printf("{%d} ", i);
            }
        }
    }

    return 0;

}

int isPrime(int amor){

    if (amor == 1){ //1 is a prime number by default
        return 1; //returning 1 == true which satisfies the above if statement
    }

    for (int i = 2; i < amor; i++){ //checks if all numbers within 2 and int amor
        if (amor % i == 0){ // are factors of int amor. if there is at least one 
            return 0; //factor, it is a composite factor
        }
    }

    return 1; // if it doesn't satisfy either of the first two, then its a prime number

}