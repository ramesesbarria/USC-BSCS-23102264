#include <stdio.h>
#define SIZE 10  // Define the size of the array

int main() {
    // Initialize an unsorted array of 10 integers
    int array[SIZE] = {8, 5, 3, 0, 9, 2, 1, 7, 6, 4};

    int gap = SIZE;   // Initialize the gap to the array size
    int swap = 1;     // Variable to track whether swaps are made

    // Continue sorting while the gap is greater than 1 or swaps are still happening
    while (gap > 1 || swap == 1) {
        // Shrink the gap using the shrink factor 1.3 (empirically chosen for efficiency)
        gap = (int)(gap / 1.3);
        if (gap < 1) {
            gap = 1;  // Ensure the minimum gap size is 1 for final bubble-like passes
        }

        swap = 0;  // Reset swap flag before each pass

        // Perform a pass through the array using the current gap
        for (int i = 0; i < SIZE - gap; i++) {
            // Compare elements that are 'gap' positions apart
            if (array[i] > array[i + gap]) {
                // Swap if they are in the wrong order
                int temp = array[i];
                array[i] = array[i + gap];
                array[i + gap] = temp;
                swap = 1;  // Mark that a swap was made
            }
        }
        // The array becomes increasingly sorted as gap reduces to 1, improving performance over Bubble Sort
    }

    // Print the sorted array
    for (int i = 0; i < SIZE; i++) {
        printf("%d - ", array[i]);
    }
    return 0;
}
