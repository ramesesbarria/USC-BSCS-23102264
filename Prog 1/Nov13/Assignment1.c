#include <stdio.h>
int main(){

    int nickels, pennies, sum, cases;

    printf("This program checks if you have enough nickels and pennies to reach a desired sum.\n");
    printf("Enter how many times you want to check: ");
    scanf("%d", &cases);
    printf("Enter the number of nickels, pennies, and sum: [N P S]\n");

    for(int i = 1; i <= cases; i++){
        printf("Case %d: ", i);
        scanf("%d %d %d",&nickels, &pennies, &sum);

        if ((nickels * 5) + pennies == sum){
            printf("True");
        } else {
            printf("False");
        }
        printf("\n");
    }
        
    }   

