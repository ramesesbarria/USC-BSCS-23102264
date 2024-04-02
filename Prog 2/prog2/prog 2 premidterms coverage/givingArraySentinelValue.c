#include <stdio.h>
int main(){

    int size;
    int elements;

    printf("How many elements do you want your array to have: ");
    scanf("%d", &size);

    int array[size + 1];

    for (int i = 0; i < size + 1; i++){
        if (i == size ){
            array[i] = -1;
        } else {
            printf("Enter element %d: ", i+1);
            scanf("%d", &elements);
            array[i] = elements;
        }
    }
    
    int counter = 0;
    int negatvieChecker = 0;
    while (negatvieChecker == 0){
        for (int i = 0; negatvieChecker < 1; i++){
            if (array[i] != -1){
                counter++;
            } else {
                negatvieChecker++;
            }
        }
    }

    printf("Your array has %d elements", counter);

    return 0;
}