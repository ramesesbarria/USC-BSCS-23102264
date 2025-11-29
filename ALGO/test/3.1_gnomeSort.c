#include <stdio.h>
#define SIZE 10  // Define the size of the array

int main() {
    // Initialize an unsorted array of 10 integers
    int array[SIZE] = {8, 5, 3, 0, 9, 2, 1, 7, 6, 4};
    
    int curr = 1; // Start from the second element (index 1)
    
    // Continue sorting until we reach the end of the array
    while (curr < SIZE) {
        // If the current element is in the correct order, move forward
        if (array[curr] >= array[curr - 1]) {
            curr++;
        } else {
            int prev = curr; // Store the current index
            
            // Swap elements until the current element is in the correct position
            while (curr > 0 && array[curr] < array[curr - 1]) {
                int temp = array[curr];
                array[curr] = array[curr - 1];
                array[curr - 1] = temp;
                curr--; // Move backward to continue checking
            }
            
            // Resume checking from the next unsorted element
            curr = prev + 1;
        }
    }

    // Print the sorted array
    for (int i = 0; i < SIZE; i++) {
        printf("%d - ", array[i]);
    }

    return 0;
}
