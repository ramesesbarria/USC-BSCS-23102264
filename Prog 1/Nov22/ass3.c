#include <stdio.h>

#define MAX_SIZE 100 

void dispArray(int arr[], int n) {
    if (n <= 0 || n > MAX_SIZE) {
        printf("Error: Invalid array size.\n");
        return;
    }

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Elements in the array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[MAX_SIZE];

    dispArray(arr, n);

    return 0;
}
