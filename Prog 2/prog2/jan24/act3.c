#include <stdio.h>

int arrayOf5Integers[5] = {};
int counter = 0;

void getInput() {
    if (counter < 5) {
        int item;
        printf("Enter an integer: ");
        scanf("%d", &item);
        if (item % 2 == 0) {
            arrayOf5Integers[counter] = item;
            counter++;
            getInput(); 
        } else {
            getInput(); 
        }
    }
}

void printArray(int index) {
    if (index < counter) {
        printf("%d ", arrayOf5Integers[index]);
        printArray(index + 1); 
    }
}

int main() {
    getInput();
    printArray(0);

    return 0;
}
