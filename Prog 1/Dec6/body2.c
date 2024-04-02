#include <stdio.h>

float v1computerSalary(int* bp, int* a, int* com, int* tax, int* gcon){
    float salary;
    *a = (*bp)*.10;
    *com = (*bp)*.30; 
    *tax = (*bp)*.20; 
    *gcon = (*bp)* .20;
    salary = *bp + *a + *com - *tax - *gcon;
    return salary;
}
void v2computerSalary(int* bp, int* a, int* com, int* tax, int* gcon){
    float salary;
    *a = (*bp)*.10;
    *com = (*bp)*.30; 
    *tax = (*bp)*.20; 
    *gcon = (*bp)* .20;
    salary = *bp + *a + *com - *tax - *gcon;
    printf("Your salary is %.2f", salary);
}
void v3computerSalary(int* bp, int* a, int* com, int* tax, int* gcon, float* s){
    float salary;
    *a = (*bp)*.10;
    *com = (*bp)*.30; 
    *tax = (*bp)*.20; 
    *gcon = (*bp)* .20;
    salary = *bp + *a + *com - *tax - *gcon;
    *s = salary;
}