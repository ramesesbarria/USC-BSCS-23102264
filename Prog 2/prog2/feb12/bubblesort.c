#include <stdio.h>

int main() {
    int array[10] = {5, 4, 26, 32, 1, 5, 3, 2, 8, 7};
    int temp;

    for (int i = 0; i < 10; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        int changes = 0;
        for (int j = 0; j < 9 - i; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                changes++;
            }
        }
        if (changes == 0){
            printf("\nProgram ended early since array is already sorted: \n");
            break;
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d\t", array[i]);
    }

    return 0;
}
