#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* compressString(char* str) {
    int length = strlen(str);
    if (length == 0) {
        return str;
    }

    char* compressed = (char*)malloc(2 * length * sizeof(char));
    int index = 0;
    int count = 1;

    for (int i = 1; i <= length; i++) {
        if (str[i] == str[i - 1]) {
            count++;
        } else {
            compressed[index++] = str[i - 1];
            if (count > 1) {
                compressed[index++] = count + '0'; 
            }
            count = 1;
        }
    }
    compressed[index] = '\0';

    return compressed;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    char* compressed = compressString(str);
    printf("Compressed string: %s\n", compressed);

    free(compressed);
    return 0;
}
