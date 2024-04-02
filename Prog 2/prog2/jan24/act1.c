#include <stdio.h>
int main(){

    int arrayOf5Integers[5] = {};

    int item, counter = 0;

    while (counter < 5){
        printf("Enter an integer: ");
        scanf("%d", &item);
        if (item % 2 == 0){
            arrayOf5Integers[counter] = item;
            counter++;
        }
    }
    
    for (int i = 0; i < counter; i++){
        printf("%d ", arrayOf5Integers[i]);
    }
}