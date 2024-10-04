#ifndef ARRAY_SET
#define ARRAY_SET

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int set[MAX];
    int size;
 } Set;

void populateSet(Set *S){
    printf("Enter a number within the range of 1 and %d\n", MAX - 1);
    int input;
    printf("Element %d: ", S->size);
    scanf("%d", &input);

    if (input >= 0 && input < MAX){
        int j;
        for (j = 0; j < S->size && S->set[j] != input; j++){}
        if (j == S->size){
            S->set[S->size++] = input;
        }
    }
}

void printSet(Set S){
    for (int i = 0; i < MAX; i++){
        printf("%d ", S.set[i]);
    }
    printf("\n");
}

Set Intersection(Set A, Set B){
    Set I  = {{}, 0};

    for (int i = 0; i < A.size; i++){
        for (int j = 0; j < B.size; j++){
            if (A.set[i] == B.set[j]){
                I.set[I.size++] = A.set[i];
            }
        }
    }
    return I;
}
Set Union(Set A, Set B){
    Set U = A;

    for (int i = 0; i < B.size; i++){
        int j;
        for (j = 0; j < U.size && B.set[i] != U.set[j]; j++){}
        if (j == U.size){
            U.set[U.size++] = B.set[i];
        }
    }

    return U;
}
Set Difference(Set A, Set B){
    Set D  = {{}, 0};

    for (int i = 0; i < A.size; i++){
        int j;
        for (j = 0; j < B.size && A.set[i] != B.set[j]; j++){}
        if (j == B.size){
            D.set[D.size++] = A.set[i];
        }
    }   
    return D;
}

#endif