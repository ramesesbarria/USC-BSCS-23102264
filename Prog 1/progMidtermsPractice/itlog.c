#include <stdio.h>

int egg(int eggType){
    float price;
    switch (eggType){
        case 1: 
        price = 15.00;
        break;
        case 2:
        price = 22.50;
        break;
        case 3: 
        price = 13.00;
        break;
    }
    return price;
}


int main(){

    float eggType, nOrders, totalCost;
    float userCash, change, discount, discountedPrice;
    
    printf("Itlog ni Noy AKIL!\n");
    printf("[1] #16 @ Php 15.00\n");
    printf("[2] #18 @ Php 22.50\n");
    printf("[3] penoy @ Php 13.00\n");

    do{
    printf("Enter your egg type: ");
    scanf("%f", &eggType);
    } while (eggType > 3 || eggType < 1);

    printf("Enter your egg orders: ");
    scanf("%f", &nOrders);

    printf("Enter amount: ");
    scanf("%f", &userCash);

    printf("\nSUMMARY\n");
        
    if (nOrders >= 150 && nOrders < 300){
        totalCost = (float)egg(eggType) * nOrders;
        discount = totalCost * 0.05;
        discountedPrice = totalCost - discount;
        change =  userCash - discountedPrice;
        
        printf("Total Cost: Php %.2f\n", totalCost);
        printf("Discount: Php %.2f\n", discount);
        printf("Discounted Price: Php %.2f\n", discountedPrice);
        if (change > 0){
            printf("Change: Php %.2f", change);
        } else if (change < 0){
            printf("Change: (Php %.2f)", change*=-1);
        }
    }
    
    if (nOrders >= 300){
        totalCost = (float) egg(eggType) * nOrders;
        discount = totalCost * 0.1;
        discountedPrice = totalCost - discount;
        change =  userCash - discountedPrice;
        
        printf("Total Cost: Php %.2f\n", totalCost);
        printf("Discount: Php %.2f\n", discount);
        printf("Discounted Price: Php %.2f\n", discountedPrice);
        if (change > 0){
            printf("Change: Php %.2f", change);
        } else if (change < 0){
            printf("Change: (Php %.2f)", change*=-1);
        }
    }

    if (nOrders < 150){
        totalCost = (float) egg(eggType) * nOrders;
        change =  userCash - totalCost;
        
        printf("Total Cost: Php %.2f\n", totalCost);
        printf("Discount: Php 0.00\n");
        printf("Change: Php %.2f\n", change);
    }
return 0;
}
    