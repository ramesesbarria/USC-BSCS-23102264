#include <stdio.h>
#include <string.h>

int main() {
    // 1. strlen
    const char *str1 = "Hello, World!";
    size_t length = strlen(str1);
    printf("1. Length of '%s': %zu\n", str1, length);

    // 2. strcpy
    char dest[20];
    strcpy(dest, "Copy me");
    printf("2. Copied string: %s\n", dest);

    // 3. strncpy
    char dest2[20];
    strncpy(dest2, "Copy me", 4);
    dest2[4] = '\0';  // Null-terminate the string
    printf("3. Partially copied string: %s\n", dest2);

    // 4. strcmp
    const char *str2 = "Hello";
    int result = strcmp(str1, str2);
    printf("4. String comparison result: %d\n", result);

    // 5. strncmp
    int result2 = strncmp(str1, str2, 5);
    printf("5. Partial string comparison result: %d\n", result2);

    // 6. strcat
    char dest3[20] = "Hello, ";
    const char *src = "World!";
    strcat(dest3, src);
    printf("6. Concatenated string: %s\n", dest3);

    // 7. strncat
    char dest4[20] = "Hello, ";
    strncat(dest4, src, 3);
    printf("7. Partially concatenated string: %s\n", dest4);

    // 8. strchr
    const char *str3 = "abcdef";
    char ch = 'c';
    char *found = strchr(str3, ch);
    printf("8. Character '%c' found at position: %ld\n", ch, found - str3);

    // 9. strrchr
    char ch2 = 'c';
    char *lastFound = strrchr(str3, ch2);
    printf("9. Last occurrence of character '%c' at position: %ld\n", ch2, lastFound - str3);

    // 10. strstr
    const char *substring = "World";
    char *substrFound = strstr(str1, substring);
    printf("10. Substring '%s' found at position: %ld\n", substring, substrFound - str1);

    // 11. strtok
    char sentence[] = "This is a sample sentence.";
    const char *delimiters = " ";
    char *token = strtok(sentence, delimiters);
    while (token != NULL) {
        printf("11. Token: %s\n", token);
        token = strtok(NULL, delimiters);
    }

    // 12. memcpy
    char source[] = "Copy this";
    char dest5[20];
    memcpy(dest5, source, sizeof(source));
    printf("12. Copied string using memcpy: %s\n", dest5);

    // 13. memmove
    char source2[] = "Move this";
    char dest6[20];
    memmove(dest6, source2, sizeof(source2));
    printf("13. Moved string using memmove: %s\n", dest6);

    // 14. memset
    char buffer[10];
    memset(buffer, '*', sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';  // Null-terminate the string
    printf("14. Memory set with '*': %s\n", buffer);

    return 0;
}
