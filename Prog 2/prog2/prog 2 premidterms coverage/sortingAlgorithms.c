#include <stdio.h>

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Flag to optimize the algorithm by checking if any swaps are made in the inner loop
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++) {
            // Push heavier elements to the end of the array
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        // If no two elements were swapped in the inner loop, the array is already sorted
        if (swapped == 0)
            break;
    }
}

// Insertion Sort Shift Variation
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements in the inner loop and insert the current element in its proper position in the outer loop
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            // Find the index of the minimum element in the unsorted part of the array
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element with the first element
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    // Sorting using Bubble Sort
    bubbleSort(arr, n);
    printf("Array sorted using Bubble Sort: ");
    printArray(arr, n);

    // Resetting the array
    int resetArr[] = {64, 34, 25, 12, 22, 11, 90};

    // Sorting using Insertion Sort
    insertionSort(resetArr, n);
    printf("Array sorted using Insertion Sort: ");
    printArray(resetArr, n);

    // Resetting the array
    int resetArr2[] = {64, 34, 25, 12, 22, 11, 90};

    // Sorting using Selection Sort
    selectionSort(resetArr2, n);
    printf("Array sorted using Selection Sort: ");
    printArray(resetArr2, n);

    return 0;
}
