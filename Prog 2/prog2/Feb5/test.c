#include <stdio.h>
#include <stdlib.h>


int* getArray();
void sorter(int*);

int main(){
    int* a = getArray();

    for (int i = 0; i < 5; i++){
        printf("%d\t", *(a + i));
    }

    printf("\n");

    sorter(a);

    return 0;
}

int* getArray(){
    int elements, n;
    printf("Enter the number of array elements: ");
    scanf("%d",  &elements);
    int* array = (int*) malloc(elements * sizeof(int));
    for (int i = 0; i < elements; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &n);
        *(array + i) = n;
    }
    return array;
}


void sorter(int* a){
    int temp;
    for (int i = 0; i < 5 - 1; i++){
        for (int j = 0; j < 5 - 1 - i; j++){
            if (*(a+j) > *(a+j+1)){
                temp = *(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1) = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++){
        printf("%d\t", *(a + i));
    }   
}
