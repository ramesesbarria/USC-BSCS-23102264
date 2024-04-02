#include <stdio.h>

int main() {
    int array[10] = {5, 4, 26, 32, 1, 5, 3, 2, 8, 7};
    int temp;

    // Selection sort algorithm
    for (int i = 0; i < 10 - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < 10; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }

    // Printing the sorted array
    for (int i = 0; i < 10; i++) {
        printf("%d\t", array[i]);
    }

    return 0;
}
