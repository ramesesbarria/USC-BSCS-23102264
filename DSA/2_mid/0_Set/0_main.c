#include "1_array.h"
#include <stdio.h>

int main(){
    int arr[5] = {1, 2, 3, 4, 8};
    Set A = {{}, 0};
    Set B = {{}, 0};

    populateSet(&A);
    populateSet(&A);
    populateSet(&A);
    populateSet(&A);
    populateSet(&A);
    populateSet(&A);

    populateSet(&B);
    populateSet(&B);
    populateSet(&B);
    populateSet(&B);
    populateSet(&B);
    populateSet(&B);

    printSet(A);
    printSet(B);

    Set I = Intersection(A, B);
    printSet(I);

    Set D = Difference(A, B);
    printSet(D);

    Set U = Union(A, B);
    printSet(U);
}