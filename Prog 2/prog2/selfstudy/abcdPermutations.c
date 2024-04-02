#include <stdio.h>

void swapCharacters(char *a, char *b);
void generatePermutations(char *str, int startIndex, int endIndex);

int main() {
    char inputString[] = "123";
    int stringLength = sizeof(inputString) / sizeof(inputString[0]) - 1;

    printf("Permutations of %s:\n", inputString);
    generatePermutations(inputString, 0, stringLength - 1);

    return 0;
}

// Function to swap two characters
void swapCharacters(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print permutations of a string
void generatePermutations(char *str, int startIndex, int endIndex) {
    if (startIndex == endIndex) {
        printf("%s\n", str);
    } else {
        for (int i = startIndex; i <= endIndex; i++) {
            // Swap the current character with the character at index 'i'
            swapCharacters(&str[startIndex], &str[i]);

            // Recursively generate permutations for the remaining characters
            generatePermutations(str, startIndex + 1, endIndex);

            // Backtrack to restore the original string
            swapCharacters(&str[startIndex], &str[i]);
        }
    }
}
