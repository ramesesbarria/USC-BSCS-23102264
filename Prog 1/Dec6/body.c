#include <stdio.h>

float v1computeGrades(int* a, int* b, int* c){
    float totalGrade;
    totalGrade = (*a)*.4 + (*b)*.3 + (*c)*.3;
    return totalGrade;
}
void v2computeGrades(int* a, int* b, int* c){
    float totalGrade;
    totalGrade = (*a)*.4 + (*b)*.3 + (*c)*.3;
    printf("%.2f is the total Grade\n", totalGrade);
}
void v3computeGrades(int* a, int* b, int* c, float* d){
    float totalGrade;
    totalGrade = (*a)*.4 + (*b)*.3 + (*c)*.3;
    *d = totalGrade;
}
