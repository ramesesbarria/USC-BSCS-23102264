#include <stdio.h>
int main(){

    int nElements, element;
    int temp;

    printf("Enter the number of elements: ");
    scanf("%d",  &nElements);

    int array[nElements];

    for (int i = 0; i < nElements; i++){
        printf("\n Enter element %d : ",i+1 );
        scanf("%d",&array[i]);
    }

    printf("\nUnsorted array: ");
    for (int i = 0; i < nElements; i++){
        printf("%d\t", array[i]);
    }

    for (int i = 0; i < nElements - 1; i++){
        for (int j = 0; j < nElements - 1 - i; j++){
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    printf("\n  Sorted array: ");
    for (int i = 0; i < nElements; i++){
        printf("%d\t", array[i]);
    }

}



