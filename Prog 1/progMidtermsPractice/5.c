#include <stdio.h> 
int lastDigit(int number); 
int main(){ 
int number; 

printf("Enter a three digit number: "); 
while (scanf("%d", &number) != 1 || number > 999 || number < 100){  //input
    while (getchar() != '\n'); 
    printf("Invalid number, re-enter: "); } 
    
    int lastNumber; int counter = 3;  //process
    switch (counter){ 
        case 3: 
        lastNumber = lastDigit(number); 
        printf("Hundreds place: %d\n", lastNumber); //ouputs
        counter--; 
        case 2: 
        lastNumber = lastDigit(number / 10); //ouputs
        printf("Tens place: %d\n", lastNumber); 
        counter--; 
        case 1: 
        lastNumber = lastDigit(number / 100); //ouputs
        printf("Ones place: %d", lastNumber); 
        break; 
    } 
        
        return 0; 
        
} 

int lastDigit(int number){  //process
    int last = 0; 
    last = number % 10; 
    return last; 
}
