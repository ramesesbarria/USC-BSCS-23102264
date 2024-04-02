#include <stdio.h>

// Function prototype to find the frequency of each element in the array
void findFrequency(int arr[], int size);

int main() {
    int nTimesInput, input, size;

    // INPUT: Prompt user for the number of integers to input
    printf("Enter how many times you want to enter an integer: ");
    scanf("%d", &nTimesInput);

    size = nTimesInput;
    int arrayOfIntegers[size];

    // INPUT: Loop to get the specified number of integers from the user
    for (int i = 1; i <= size; i++) {
        printf("Input %d: ", i);
        scanf("%d", &input);

        arrayOfIntegers[i - 1] = input;
    }

    // OUTPUT: Display the entered integers
    printf("You entered: ");
    for (int i = 1; i <= size; i++) {
        printf("%d, ", arrayOfIntegers[i - 1]);
    }
    printf("\n");

    // PROCESS: Call the function to find and display the frequency of each element
    findFrequency(arrayOfIntegers, size);

    return 0;
}

// PROCESS: Function to find and display the frequency of each element in the array
void findFrequency(int arr[], int size) {
    // PROCESS: Sort the array in ascending order using Bubble Sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Bubble Sort: Compare adjacent elements and swap if in the wrong order
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // PROCESS: Find and display the frequency of each element in the sorted array
    for (int i = 0; i < size; i++) {
        if (arr[i] != -1) {
            int count = 1;

            // Count frequency and mark duplicates
            for (int j = i + 1; j < size; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    arr[j] = -1; // Mark duplicate to avoid recounting
                }
            }

            // OUTPUT: Display the frequency of the current element
            if (count > 1) {
                printf("%d can be found %d times in the array.\n", arr[i], count);
            } else {
                printf("%d can be found %d time in the array.\n", arr[i], count);
            }
        }
    }
}
