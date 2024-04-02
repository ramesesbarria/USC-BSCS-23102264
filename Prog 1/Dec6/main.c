#include <stdio.h>
#include "headers.c"
#include "body.c"
int main(){
    
    int projectGrade, assGrade, examGrade;
    float totalGrade;

    printf("Grade Calculator\n");
    printf("----------------\n");

    printf("Enter your project grade: ");
    scanf("%d", &projectGrade);

    printf("Enter your average assignment grade: ");
    scanf("%d", &assGrade);

    printf("Etner your average exam grade: ");
    scanf("%d", &examGrade);

    printf("----------------\n");
    printf("version 1\n");
    printf("----------------\n");

    float tGrade = v1computeGrades(&projectGrade, &assGrade, &examGrade);
    printf("%.2f is the total Grade", tGrade);

    printf("\n----------------\n");
    printf("version 2\n");
    printf("----------------\n");

    v2computeGrades(&projectGrade, &assGrade, &examGrade);

    printf("----------------\n");
    printf("version 3\n");
    printf("----------------\n");

    v3computeGrades(&projectGrade, &assGrade, &examGrade, &totalGrade);
    printf("%.2f is the total Grade", totalGrade);

}