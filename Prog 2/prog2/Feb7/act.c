#include <stdio.h>
#include <stdlib.h>
int* getArray();
void filter(int*);
void printArray(int*);

int main(){
    int* array = getArray();
    filter(array);
    printArray(array);
}
int* getArray(){
    int size, element;
    printf("Enter the number of inputs for your array: ");
    scanf("%d", &size);
    int* array = (int*) malloc ((size + 1) * sizeof(int));
    for (int i = 0; i < size; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        *(array + i) = element;
    }
    *(array + size) = -1;
    return array;
}
void filter(int* array){
    int currentIndex = 0;
    for (int i = 0; array[i] >= 0; i++){
        if (*(array + i) % 2 == 0){
            array[currentIndex++] = *(array + i);
        }
    }
    *(array + currentIndex) = -1;
}
void printArray(int* array){
    for (int i = 0; *(array + i) >= 0; i++){
        printf("%d\t", *(array + i));
    }
}