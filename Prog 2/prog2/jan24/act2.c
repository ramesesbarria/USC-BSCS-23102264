#include <stdio.h>

void scanThis(int arr[], int size) {
    int item, counter = 0;

    while (counter < size) {
        printf("Enter an integer: ");
        scanf("%d", &item);
        if (item % 2 == 0) {
            arr[counter] = item;
            counter++;
        }
    }
}

void printThis(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arrayOf5Integers[5] = {};

    scanThis(arrayOf5Integers, 5);
    printThis(arrayOf5Integers, 5);

    return 0;
}
