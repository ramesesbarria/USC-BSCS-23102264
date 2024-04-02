#include <stdio.h>

int orange(int nOranges);
int potato (int nPotato);
int pork (int nPork);

int main(){

    printf("I sell oranges, potatoes and pork!\n");
    printf("At a minimum, you have to buy at least: \n");
    printf("1) Five boxes of oranges which has 50 oranges per box and is at 16.50 per orange\n");
    printf("2) Seven boxes of potatoes which has 60 potatoes per box and is at 21.23 per potato\n");
    printf("3) 35 kilos of pork at 160 per kilo\n");

    int nOranges, nPotato, nPork;
    float tPriceOrange, tPricePotato, tPricePork;


        printf("\nEnter number of oranges: ");
        while (scanf("%d", &nOranges) != 1 || nOranges < 250 || nOranges < 0) {
            // Clear the input buffer
            while (getchar() != '\n');
            printf("Invalid input or not enough oranges. Buy more oranges please: ");
        }

        tPriceOrange = orange(nOranges);
        printf("You bought %d oranges, the total price of all of these is %.2f.\n", nOranges, tPriceOrange);

        printf("\nEnter number of potatoes: ");
        while (scanf("%d", &nPotato) != 1 || nPotato < 420 || nPotato < 0) {
            // Clear the input buffer
            while (getchar() != '\n');
            printf("Invalid input or not enough potatoes. Buy more potatoes please: ");
        }

        tPricePotato = potato(nPotato);
        printf("You bought %d potatoes, the total price of all of these is %.2f.\n", nPotato, tPricePotato);

        printf("\nEnter number of kilos of pork: ");
        while (scanf("%d", &nPork) != 1 || nPork < 35 || nPork < 0) {
            // Clear the input buffer
            while (getchar() != '\n');
            printf("Invalid input or not enough pork. Buy more pork please: ");
        }

        tPricePork = pork(nPork);
        printf("You bought %d kilos of pork, the total price of all of these is %.2f.\n", nPork, tPricePork);

        float totalSales = ((tPriceOrange * .30) + (tPricePotato * .30) + (tPricePork * .40));


        printf("\nBased on the sales I made today, my products are in: ");
        if (totalSales > 1000){
            printf("High Demand");
        } else if ((totalSales > 500) && (totalSales < 1000)){
            printf("Average Demand");
        } else {
            printf("Low Demand");
        }

        
    
    return 0;


}

int orange(int nOranges){

    float price;
    price = nOranges * 16.50;
    return price;
}

int potato (int nPotato){

    float price;
    price = nPotato * 21.23;
    return price;
}

int pork (int nPork){

    float price;
    price = nPork * 160;
    return price;
}
