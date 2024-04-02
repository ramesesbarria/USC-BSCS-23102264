#include <stdio.h>
#include <stdlib.h>

int* makeArray(int size);
int askSize();
void swap(int*, int*);
void sorter(int*, int);
void printer(int*, int);

int main(){
    int size = askSize();
    int* array = makeArray(size);
    sorter(array, size);
    printer(array, size);
    free(array);
}

int askSize(){
    int size;
    printf("Enter the number of elements in your array: ");
    scanf("%d", &size);
    return size;
}

int* makeArray(int size){
    int *array = (int*) malloc(size * sizeof(int));
    int element;
    for (int i = 0; i < size; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        *(array + i) = element;
    }
    return array;
}

void sorter(int* array, int size){
    int temp;
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - 1 - i; j++){
            if (*(array + j) > *(array + j + 1)){
               swap((array + j),  (array + j + 1));  
            }
        }
    }
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printer(int* array, int size){
    printf("\nYour sorted array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t", *(array + i));
    }
}