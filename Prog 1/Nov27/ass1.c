// Input: User inputs the number of items and their names, as well as the type of each item.
#include <stdio.h>
#include <string.h>

// Process: Sorts and counts items based on their types (meat, drinks, fruit, vegetables).
void itemSorter(int nItems);

int main(){

    // Input: User inputs the number of items in the basket.
    int nItems;
    printf("Enter how many items are in your basket: ");
    scanf("%d", &nItems);

    // Process: Calls the itemSorter function to process and display the sorted items.
    itemSorter(nItems);
}

// Process: Sorts and counts items based on their types (meat, drinks, fruit, vegetables).
void itemSorter(int nItems){

    char itemName[100];
    char meat[100] = "Meat and poultry: ";
    char drinks[100] = "Dairy and drinks: ";
    char fruit[100] = "Fruit: ";
    char vegetables[100] = "Vegetable: ";

    int itemType;

    // Input: User inputs the type of each item (meat, drinks, fruit, vegetables).
    printf("For context:\n1: meat\n2: drinks\n3: fruits\n4: vegetables\n");
    for (int i = 1; i <= nItems; i++){
        printf("\nItem %d: ", i);
        scanf("%s", &itemName);
        printf("Item Type[1,2,3,4]: ");
        scanf("%d", &itemType);

        // Process: Appends the item name to the corresponding category.
        switch (itemType){
            case 1:
                strcat(meat, " ");
                strcat(meat, itemName);
                strcat(meat, "-");
                break;
            case 2:
                strcat(drinks, " ");
                strcat(drinks, itemName);
                strcat(drinks, "-");
                break;
            case 3:
                strcat(fruit, " ");
                strcat(fruit, itemName);
                strcat(fruit, "-");
                break;
            case 4:
                strcat(vegetables, " ");
                strcat(vegetables, itemName);
                strcat(vegetables, "-");
                break;
        }            
    }

    // Output: Displays the sorted items for each category.
    printf("\n%s", meat);
    printf("\n%s", drinks);
    printf("\n%s", fruit);
    printf("\n%s", vegetables);
}
