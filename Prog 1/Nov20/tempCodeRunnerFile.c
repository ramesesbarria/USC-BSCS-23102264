#include <stdio.h>
int main(){

    int nTimesInput, input, size;

    printf("Enter how many times you want to enter an integer: ");
    scanf("%d", &nTimesInput);

    size = nTimesInput;
    int arrayOfIntegers[size];

    int evenCount = 0, oddCount = 0;

    for (int i = 1; i <= size; i++) {
        printf("Input %d: ", i);
        scanf("%d", &input);
        arrayOfIntegers[i - 1] = input;
        if (input % 2 == 0){
            evenCount++;
        } else {
            oddCount++;
        }

    }

    int arrayOfEven[evenCount];
    int arrayOfOdd[oddCount];

    int n = 0;
    for(int i = 0; i < size; i++){
        if(arrayOfIntegers[i] % 2 == 0){
            arrayOfEven[n] = arrayOfIntegers[i];
            n++;
        }
    }
    int m = 0;
    for(int i = 0; i < size; i++){
        if(arrayOfIntegers[i] % 2 != 0){
            arrayOfOdd[m] = arrayOfIntegers[i];
            m++;
        }
    }

    printf("You entered: ");
    for (int i = 1; i <= size; i++) {
        printf("%d, ", arrayOfIntegers[i - 1]);
    }

    printf("\n");

    printf("Integers in the even array: ");
    for (int i = 0; i < evenCount; i++){
        printf("%d, ", arrayOfEven[i]);
    }

    printf("\n");

    printf("Integers in the odd array: ");
    for (int i = 0; i < oddCount; i++){
        printf("%d, ", arrayOfOdd[i]);
    }
   
    return 0;

}