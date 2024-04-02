#include <stdio.h>
#include <string.h>
 
int main() {
    // strcpy: Copies a string
    char source[] = "Hello";
    char destination[20];
    strcpy(destination, source);
    printf("strcpy: Copied string: %s\n", destination);
    printf("parameters: (destination, source);\n");
 
    // strncpy: Copies a certain number of characters from one string to another
    char source2[] = "Hello, World!";
    char destination2[20];
    strncpy(destination2, source2, 5);
    destination2[5] = '\0'; // Null-terminate the string
    printf("\nstrncpy: Copied string: %s\n", destination2);
    printf("parameters: (destination, source, num);\n");
 
    // strcat: Concatenates two strings
    char str1[20] = "Hello ";
    char str2[] = "World!";
    strcat(str1, str2);
    printf("\nstrcat: Concatenated string: %s\n", str1);
    printf("parameters: (destination, source);\n");
 
    // strncat: Concatenates a certain number of characters from one string to another
    char str3[20] = "Hello ";
    char str4[] = "World!";
    strncat(str3, str4, 3);
    printf("\nstrncat: Concatenated string: %s\n", str3);
    printf("parameters: (destination, source, num);\n");
 
    // strcmp: Compares two strings
    char str5[] = "hello";
    char str6[] = "Hello";
    int result = strcmp(str5, str6);
    printf("\nstrcmp: Comparison result: %d\n", result);
    printf("parameters: (string1, string2);\n");
 
    // strncmp: Compares a certain number of characters of two strings
    char str7[] = "hello";
    char str8[] = "Hello";
    int result2 = strncmp(str7, str8, 3);
    printf("\nstrncmp: Comparison result: %d\n", result2);
    printf("parameters: (string1, string2, num);\n");
 
    // strlen: Calculates the length of a string
    char str9[] = "Hello";
    printf("\nstrlen: Length of string '%s' is %zu\n", str9, strlen(str9));
    printf("parameters: (string);\n");
 
    // strstr: Finds the first occurrence of a substring in a string
    char str12[] = "Hello, World!";
    char *substr = strstr(str12, "World");
    printf("\nstrstr: Substring 'World' found in '%s' at position: %ld\n", str12, substr - str12);
    printf("parameters: (string, substring);\n");
 
    // strtok: Splits a string into tokens
    char str13[] = "Hello,World,Bye,I'm,Back,Okay,Bye";
    char *token = strtok(str13, ",");
    while (token != NULL) {
        printf("\nstrtok: Token: %s\n", token);
        printf("parameters: (string, delimiter);\n");
        token = strtok(NULL, ",");
    }

 
 
    // memcpy: Copies a block of memory
    char source15[] = "Hello";
    char destination15[20];
    memcpy(destination15, source15, strlen(source15) + 1);
    printf("\nmemcpy: Copied string: %s\n", destination15);
    printf("parameters: (destination, source, size);\n");
 
    // memmove: Moves a block of memory to another location
    char str16[] = "oldstring";
    memmove(str16 + 3, str16, strlen(str16) + 1);
    printf("\nmemmove: After moving: %s\n", str16);
    printf("parameters: (destination, source, size);\n");
 
    // memcmp: Compares two blocks of memory
    char str17[] = "abc";
    char str18[] = "abd";
    int result3 = memcmp(str17, str18, strlen(str17));
    printf("\nmemcmp: Comparison result: %d\n", result3);
    printf("parameters: (block1, block2, size);\n");
 
    return 0;
}