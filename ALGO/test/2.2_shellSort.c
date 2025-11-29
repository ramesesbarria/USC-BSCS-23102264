#include <stdio.h>
#define SIZE 10  // Define the size of the array

int main() {
    // Initialize an unsorted array of 10 integers
    int array[SIZE] = {8, 5, 3, 0, 9, 2, 1, 7, 6, 4};

    // Start with a large gap and reduce it
    for (int gap = SIZE / 2; gap > 0; gap /= 2) {
        // Perform a gapped insertion sort for the current gap size
        for (int i = gap; i < SIZE; i++) {
            int temp = array[i]; // Store the element to be positioned
            int j;
            
            // Shift earlier gap-sorted elements up until the correct location is found
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap]; // Move the larger element to the right
            }
            
            // Place the stored element in its correct position
            array[j] = temp;
        }
    }

    // Print the sorted array
    for (int i = 0; i < SIZE; i++) {
        printf("%d - ", array[i]);
    }

    return 0;
}
