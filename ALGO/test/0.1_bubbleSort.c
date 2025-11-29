#include <stdio.h>
#define SIZE 10  // Define the size of the array

int main(){
    // Initialize an unsorted array of 10 integers
    int array[SIZE] = {8, 5, 3, 0, 9, 2, 1, 7, 6, 4};

    // Outer loop controls the number of passes
    for (int i = 0; i < SIZE - 1; i++){ 
        // Inner loop performs the comparisons and swaps adjacent elements if needed
        for (int j = 0; j < SIZE - i - 1; j++){ 
            // If the current element is greater than the next element, swap them
            if (array[j] > array[j+1]){
                int temp = array[j];      // Store the larger value in a temporary variable
                array[j] = array[j+1];    // Move the smaller value to the left
                array[j+1] = temp;        // Place the larger value to the right
            }
        }
        // At the end of each pass, the largest unsorted element is placed at its correct position
    }

    // Print the sorted array
    for (int i = 0; i < SIZE; i++){
        printf("%d - ", array[i]);
    }
}
