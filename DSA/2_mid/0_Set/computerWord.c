#include <stdio.h>
#include <stdlib.h>
#define MAX (sizeof(unsigned char) * 8)

typedef unsigned char Set;
typedef enum {TRUE, FALSE} Boolean; 

void init(Set *S);
void displayBitPattern(Set S);
void insertElem(Set *S, int elem);
void deleteElem(Set *S, int elem);
void displayElem(Set S);
Set Union(Set A, Set B){
    Set C = 0;  
    for(int i = 0; i < MAX; i++){
        if((1 & (A >> i)) || (1 & (B >> i))){  
            C |= (1 << i);
        }
    }
    return C;  
}
Set Intersection(Set A, Set B){
    Set C = 0;
    for(int i = 0; i < MAX; i++){
        if((1 & (A >> i)) && (1 & (B >> i))){
            C |= (1 << i);
        }
    }
    return C;
}
Set Difference(Set A, Set B){
    Set C = 0;
    for (int i = 0; i < MAX; i++){
        if((1 & (A >> i)) && !(1 & (B >> i))){
            C |= (1 << i);
        }
    }
    return C;
}


int main(){
    Set A;
    Set B;
    
    init(&A);
    init(&B);

    insertElem(&A, 1);
    insertElem(&A, 2);
    insertElem(&A, 3);
    insertElem(&B, 3);
    insertElem(&B, 4);
    insertElem(&B, 5);
    

    Set U;
    U = Union(A, B);
    printf("Bit pattern: ");
    displayBitPattern(U);
    printf("\nElements: ");
    displayElem(U);
    printf("\n");

    Set I;
    I = Intersection(A, B);
    printf("Bit pattern: ");
    displayBitPattern(I);
    printf("\nElements: ");
    displayElem(I);
    printf("\n");

    Set D;
    D = Difference(A, B);
    printf("Bit pattern: ");
    displayBitPattern(D);
    printf("\nElements: ");
    displayElem(D);
    printf("\n");
}

void init(Set* S){
    (*S) = 0;
}

void insertElem(Set *S, int elem){
    if (elem < MAX){
        (*S) |= (1 << elem);
    }
}

void deleteElem(Set *S, int elem){
    if (elem < MAX){
        (*S) &= ~(1 << elem);
    }
}

void displayElem(Set S){
    for (int i = 0; i < MAX; i++){
        if (((S >> i) & 1) == 1){
            printf("%d", i);
        }
    }
}

void displayBitPattern(Set S){
    for(int Shift = MAX - 1; Shift >= 0; Shift--){
        printf("%d", (S >> Shift) & 1);
    }
}

