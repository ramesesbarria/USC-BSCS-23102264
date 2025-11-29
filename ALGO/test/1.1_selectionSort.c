#include <stdio.h>
#define SIZE 10  // Define the size of the array

int main(){
    // Initialize an unsorted array of 10 integers
    int array[SIZE] = {8, 5, 3, 0, 9, 2, 1, 7, 6, 4};

    // Outer loop moves through each element in the array
    for (int i = 0; i < SIZE; i++){
        int sIndex = i; // Assume the current index has the smallest value

        // Inner loop finds the smallest element in the unsorted portion
        for (int j = i; j < SIZE; j++){
            if (array[sIndex] > array[j]){  // Compare current smallest with another element
                sIndex = j;  // Update index if a smaller element is found
            }
        }

        // Swap the smallest found element with the first unsorted element
        int temp = array[i];
        array[i] = array[sIndex];
        array[sIndex] = temp;
    }

    // Print the sorted array
    for (int i = 0; i < SIZE; i++){
        printf("%d - ", array[i]);
    }

    return 0;
}
