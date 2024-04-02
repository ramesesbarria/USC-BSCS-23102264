#include <stdio.h>
#include <stdlib.h>

int* arrayGiverMalloc();
int* arrayGiverCalloc();

int main(){

    int array1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int* arrayM = arrayGiverMalloc();
    int* arrayC = arrayGiverCalloc();

    for (int i = 0; i < 10; i++){
        printf("%d\t", *(arrayM + i));
    } printf("\n");
    for (int i = 0; i < 10; i++){
        printf("%d\t", *(arrayC + i));
    } printf("\n");

    int* newArrayM = realloc(arrayM, sizeof(int) * 15);
    for (int i = 0; i < 15; i++){
        printf("%d\t", *(newArrayM + i));
    } printf("\n");

    int* newArrayC = realloc(arrayC, sizeof(int) * 15);
    for (int i = 0; i < 15; i++){
        printf("%d\t", *(newArrayC + i));
    } printf("\n");

    free(arrayM);
    free(arrayC);
    free(newArrayM); 
    free(newArrayC);

}

int* arrayGiverMalloc(){

    int size;
    int* arrayM = (int*) malloc (sizeof(int) * 10);

    for (int i = 0; i < 10; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &size);
        *(arrayM + i) = size;
    }

    return arrayM;
}

int* arrayGiverCalloc(){

    int size;
    int* arrayC = (int*) calloc (10, sizeof(int) * 10);

    for (int i = 0; i < 5; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &size);
        *(arrayC + i) = size;
    }

    return arrayC;
}