#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ASCII_SIZE 256

void countOccurrences(char *str) {
    int count[ASCII_SIZE] = {0};
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        char currentChar = str[i];
        int asciiValue = (int)currentChar;
        count[asciiValue]++;
    }

    printf("Unique characters with their occurrences (sorted by ASCII value):\n");
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (count[i] > 0) {
            printf("%c: %d\n", (char)i, count[i]);
        }
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    countOccurrences(str);

    return 0;
}
