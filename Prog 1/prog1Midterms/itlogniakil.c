#include <stdio.h>
int main(){
    int eggType, eggOrders;
    float cash, eggPrice, totalCost, change, dAmount, dPrice;

    printf("Itlog ni Noy AKIL!\n");
    printf("[1] #16 @ Php 15.00\n");
    printf("[2] #18 @ Php 22.50\n");
    printf("[3] penoy @ Php 13.00\n");

    do {
        printf("Enter your egg type: ");
        scanf("%d", &eggType);
    } while (eggType > 3 || eggType < 0);

    printf("Enter total egg orders: ");
    scanf("%d", &eggOrders);

    printf("Enter amount: ");
    scanf("%f", &cash);

    switch (eggType){
        case 1:
            eggPrice = 15.00;
            break;
        case 2:
            eggPrice = 22.50;
            break;
        case 3:
            eggPrice = 13.00;
            break;
    }

    totalCost = eggPrice * eggOrders;

    int discount = 0;
    if (eggOrders >= 150 && eggOrders < 300){
        discount = 1;
        dAmount = totalCost * 0.05;
        dPrice = totalCost - dAmount;
        change = cash - dPrice;
    } else if (eggOrders >= 300){
        discount = 2;
        dAmount = totalCost * 0.1;
        dPrice = totalCost - dAmount;
        change = cash - dPrice;
    } else {
        change = cash - totalCost;
    }

    printf("\nSUMMARY\n");
    printf("Total Cost: Php %.2f\n", totalCost);

    switch (discount){
        case 0:
            printf("Discount: Php 0.00\n");
            if (change >= 0){
                printf("Change: Php %.2f", change);
            } else if (change < 0){
                change *= -1;
                printf("Change: (Php %.2f)", change);
            }
            break;

        case 1:
            printf("Discount: Php %.2f\n", dAmount);
            printf("Discounted Price: Php %.2f\n", dPrice);
            if (change >= 0){
                printf("Change: Php %.2f", change);
            } else if (change < 0){
                change *= -1;
                printf("Change: (Php %.2f)", change);
            }
            break;

        case 2:
            printf("Discount: Php %.2f\n", dAmount);
            printf("Discounted Price: Php %.2f\n", dPrice);
            if (change >= 0){
                printf("Change: Php %.2f", change);
            } else if (change < 0){
                change *= -1;
                printf("Change: (Php %.2f)", change);
            }
            break;
    }

    return 0;
}
