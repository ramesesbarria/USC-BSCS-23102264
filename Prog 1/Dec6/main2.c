#include <stdio.h>
#include "headers2.c"
#include "body2.c"
int main(){

    int basicPay, allowance, commision, tax, gContri;
    float totalSalary;

    printf("Salary Calculator\n");
    printf("----------------\n");

    printf("Enter your basic pay: ");
    scanf("%d", &basicPay);

    printf("----------------\n");
    printf("version 1\n");
    printf("----------------\n");

    float ts = v1computerSalary(&basicPay, &allowance, &commision, &tax, &gContri);
    printf("Your salary is %.2f", ts);

    printf("\n----------------\n");
    printf("version 2\n");
    printf("----------------\n");

    v2computerSalary(&basicPay, &allowance, &commision, &tax, &gContri);

    printf("\n----------------\n");
    printf("version 3\n");
    printf("----------------\n");

    v3computerSalary(&basicPay, &allowance, &commision, &tax, &gContri, &totalSalary);

    printf("Your salary is %.2f", totalSalary);

}
