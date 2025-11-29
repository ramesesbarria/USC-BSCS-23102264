#include <stdio.h>
#define SIZE 10  // Define the size of the array

int main(){
    // Initialize an unsorted array of 10 integers
    int array[SIZE] = {8, 5, 3, 0, 9, 2, 1, 7, 6, 4};

    // Start from the second element (index 1) and insert it into the sorted part
    for (int i = 1; i < SIZE; i++){
        int j = i;  // Set j as the current index

        // Move elements of the sorted part to the right if they are larger than array[j]
        while(j > 0 && array[j-1] > array[j]){
            // Swap adjacent elements to shift the larger one to the right
            int temp = array[j-1];
            array[j-1] = array[j];
            array[j] = temp;
            j--;  // Move to the previous position to continue shifting
        }
    }

    // Print the sorted array
    for (int i = 0; i < SIZE; i++){
        printf("%d - ", array[i]);
    }

    return 0;
}
