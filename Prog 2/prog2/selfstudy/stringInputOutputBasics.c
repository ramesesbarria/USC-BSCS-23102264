#include <stdio.h>
#include <string.h>

int main() {

    char string1[100];
    char string2[100];

    printf("Enter a string [Method 1]: ");
    scanf(" %[^\n]", string1);
    getchar(); 
    printf("You entered: %s\n", string1);
    printf("This method uses scanf to scan until it encounters a new line\n");

    printf("\nEnter a string [Method 2]: ");
    fgets(string2, sizeof(string2), stdin);
    printf("You entered: %s", string2);
    printf("This method uses fgets which has three parameters (char array, sizeof(array), stdin)\n");

    return 0;
}
