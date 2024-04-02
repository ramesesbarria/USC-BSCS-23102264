#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';
    int length = strlen(str);

    int counter = 0;
    int currentWordLength = 0;
    int longestWordLength = 0;
    char longestWord[100]; // Assuming the longest word can be at most 100 characters

    for (int i = 0; i <= length; i++) {
        char currentChar = str[i];
        int asciiValue = (int)currentChar;
        if (asciiValue != 32 && asciiValue != 0) {
            counter++;
            currentWordLength++;
        } else {
            if (currentWordLength > longestWordLength) {
                longestWordLength = currentWordLength;
                strncpy(longestWord, &str[i - currentWordLength], currentWordLength);
                longestWord[currentWordLength] = '\0';
            }
            currentWordLength = 0;
        }
    }

    printf("Length of longest word: %d\n", longestWordLength);
    printf("Longest word is: %s\n", longestWord);

    return 0;
}
