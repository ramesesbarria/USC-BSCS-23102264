#include <stdio.h>
#include <string.h>

// Process: Function to calculate the total amount for each category and determine the most saleable category
void calculateTotalAmount(int nItems);

int main() {
    // Input: User inputs the number of items in the basket.
    int nItems;
    printf("Enter how many items are in your basket: ");
    scanf("%d", &nItems);

    // Process: Calls the calculateTotalAmount function to process and display the total amounts.
    calculateTotalAmount(nItems);

    return 0;
}

// Process: Function to calculate the total amount for each category and determine the most saleable category
void calculateTotalAmount(int nItems) {
    char itemName[100];
    int itemType;
    float price;
    float totalMeat = 0, totalDairyDrinks = 0, totalFruit = 0, totalVegetable = 0;
    float mostSaleableTotal = 0;
    char mostSaleableCategory[100];

    // Input: User inputs the type, name, and price of each item.
    printf("For context:\n1: meat\n2: drinks\n3: fruits\n4: vegetables\n");

    for (int i = 1; i <= nItems; i++) {
        printf("\nItem %d: ", i);
        scanf("%s", itemName);
        printf("Item Type[1,2,3,4]: ");
        scanf("%d", &itemType);

        // Input: User inputs the price per unit of each item.
        printf("Price per unit: ");
        scanf("%f", &price);

        // Process: Calculates the total amount for each category based on the entered item type.
        switch (itemType) {
            case 1:
                totalMeat += price;
                break;
            case 2:
                totalDairyDrinks += price;
                break;
            case 3:
                totalFruit += price;
                break;
            case 4:
                totalVegetable += price;
                break;
        }
    }

    // Output: Displays the subtotal for each category.
    printf("\nSubtotal per category:\n");
    printf("Meat and poultry: %.2f\n", totalMeat);
    printf("Dairy and drinks: %.2f\n", totalDairyDrinks);
    printf("Fruit: %.2f\n", totalFruit);
    printf("Vegetable: %.2f\n", totalVegetable);

    // Process: Determines the most saleable category.
    if (totalMeat > mostSaleableTotal) {
        mostSaleableTotal = totalMeat;
        strcpy(mostSaleableCategory, "Meat and poultry");
    }
    if (totalDairyDrinks > mostSaleableTotal) {
        mostSaleableTotal = totalDairyDrinks;
        strcpy(mostSaleableCategory, "Dairy and drinks");
    }
    if (totalFruit > mostSaleableTotal) {
        mostSaleableTotal = totalFruit;
        strcpy(mostSaleableCategory, "Fruit");
    }
    if (totalVegetable > mostSaleableTotal) {
        mostSaleableTotal = totalVegetable;
        strcpy(mostSaleableCategory, "Vegetable");
    }

    // Output: Displays the total amount and the most saleable category.
    float totalAmount = totalMeat + totalDairyDrinks + totalFruit + totalVegetable;
    printf("\nTotal: %.2f\n", totalAmount);
    printf("The most saleable item in this transaction is: %s\n", mostSaleableCategory);
}
