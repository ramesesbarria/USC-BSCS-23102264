#include <stdio.h>

int* reverser(int[]);
int main(){

    int size;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    int List[size + 1];
    int element;

    for (int i = 0; i < size; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        List[i] = element;
    }
    List[size] = -1;

    printf("Original array: [");
    for (int i = 0; i < size; i++){
        if (i < size - 1){
            printf("%d, ", List[i]);
        } else {
            printf("%d", List[i]);
        }
    }
    printf("]");

    int* reversed = reverser(List);

    

    printf("Reverse array: [");
    for (int i = 0; i < size; i++){
        if (i < size - 1){
            printf("%d, ", *(reversed + i));
        } else {
            printf("%d", *(reversed + i));
        }
    }
    printf("]");
}

int* reverser(int arr[]){

    int size = 0;
    int sentinel = 0;

    while (sentinel == 0){
        for (int i = 0; sentinel == 0; i++){
            if (arr[i] != -1){
                size++;
            } else {
                sentinel++;
            }
        }
    }
    printf("\n");
    int* reversed = (int*) calloc (size, sizeof(int));
    int j = 0;
    for (int i = size - 1; i >= 0; i--){
        reversed[j] = arr[i];
        j++;
    }

    return reversed;
    
}