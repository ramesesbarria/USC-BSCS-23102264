#include <stdio.h>
int main(){

    int size;

    printf("Enter how many elements you want your array to have: ");
    scanf("%d", &size);

    int array[size];
    
    for (int i = 0; i < size; i++){
        printf("Element %d - index %d: ", i + 1, i);
        scanf("%d", &array[i]);
    }

    printf("Unsorted array:");
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }printf("\n");

    //bubble sort

    for (int i = 0; i < size - 1; i++){
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++){
            if (array[j] > array[j + 1]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped++;
            }
        }
        if (swapped == 0){
            break;
        }
    }

    printf("Sorted array:  ");
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }printf("\n");
}