#include <stdio.h>

int isPrime(int num){ // process
    if (num == 1){
        return 1;
    }
    for (int i = 2; i < num; i++){
        if (num % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int num;
    int yes = 0;
    int counter = 0;

    do{
    printf("Enter a num: ");
    scanf("%d", &num); // input

    if (isPrime(num)){ //output
        printf("%d is a prime number.", num);
    } else {
        printf("%d is not a prime number.", num);
    }
    printf("\nGo again? [yes: 0, no: 1]");
    scanf("%d", &yes);

    if (yes == 1){
        counter++;
    }
    }while(counter != 1);
return 0;
}