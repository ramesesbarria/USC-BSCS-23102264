#include <stdio.h>
#include <string.h>

int main() {
    char name[20];
    int age;
    float height;

    // scanf: Reads input from the standard input stream
    printf("Enter your name, age, and height: ");
    scanf("%s %d %f", name, &age, &height);

    // gets: Reads a line from the standard input stream
    char sentence[100];
    printf("Enter a sentence: ");
    gets(sentence);

    // printf: Prints formatted output to the standard output stream
    printf("\nName: %s\nAge: %d\nHeight: %.2f\n", name, age, height);

    // puts: Writes a string to the standard output stream
    puts("\nYou entered:");
    puts(sentence);

    return 0;
}
