#include <stdio.h>
int main(){

    int nTimesInput, input, size;

    printf("Enter how many times you want to enter an integer: ");
    scanf("%d", &nTimesInput); // INPUT: Prompts the user to enter how many integers user want's to input.

    size = nTimesInput; // assigns nTimesInput to size so that size can be utilized to set the size of the universal array.
    int arrayOfIntegers[size]; // declaration of array of type int with size: 'size' named arrayOfIntegers

    int evenCount = 0, oddCount = 0;

    for (int i = 1; i <= size; i++) { //INPUT: Loops through 'size' number of times to get integer values from user.
        printf("Input %d: ", i);
        scanf("%d", &input);
        arrayOfIntegers[i - 1] = input; //For each time it loops, starting at 0 until size, value scanned from user is appended to i position of arrayOfIntegers array.
        if (input % 2 == 0){
            evenCount++; //Checks how many integers are even or odd. Utilized later for the declaration of the size of array of even/odd integers.
        } else {
            oddCount++;
        }

    }

    int arrayOfEven[evenCount];
    int arrayOfOdd[oddCount];

    int n = 0;
    for(int i = 0; i < size; i++){ // PROCESS: loops through arrayOfIntegers and adds every even value
        if(arrayOfIntegers[i] % 2 == 0){
            arrayOfEven[n] = arrayOfIntegers[i]; // If the integer successfully appends, meaning, it is even, n is incremented to move onto the next available position of the array
            n++;
        }
    }
    int m = 0;
    for(int i = 0; i < size; i++){ // Same process as ODD
        if(arrayOfIntegers[i] % 2 != 0){
            arrayOfOdd[m] = arrayOfIntegers[i];
            m++;
        }
    }

    printf("You entered: ");
    for (int i = 1; i <= size; i++) { //Loops throguh and prints all elements in the universal array
        printf("%d, ", arrayOfIntegers[i - 1]);
    }

    printf("\n");

    printf("Integers in the even array: "); //loops through and prints all elements in the even array
    for (int i = 0; i < evenCount; i++){
        printf("%d, ", arrayOfEven[i]);
    }

    printf("\n");

    printf("Integers in the odd array: "); //Loops and prints all elements in the odd array
    for (int i = 0; i < oddCount; i++){
        printf("%d, ", arrayOfOdd[i]);
    }
   
    return 0;

}