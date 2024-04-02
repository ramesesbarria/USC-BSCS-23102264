#include <stdio.h>
#include <ctype.h>

int main() {
    // isalpha: Checks if a character is an alphabetic character
    char ch1 = 'A';
    printf("isalpha: Character '%c' is %s\n", ch1, isalpha(ch1) ? "alphabetic" : "not alphabetic");

    // isdigit: Checks if a character is a digit
    char ch2 = '7';
    printf("isdigit: Character '%c' is %s\n", ch2, isdigit(ch2) ? "a digit" : "not a digit");

    // ispunct: Checks if a character is a punctuation character
    char ch3 = '$';
    printf("ispunct: Character '%c' is %s\n", ch3, ispunct(ch3) ? "a punctuation character" : "not a punctuation character");

    // isspace: Checks if a character is a white-space character
    char ch4 = ' ';
    printf("isspace: Character '%c' is %s\n", ch4, isspace(ch4) ? "a white-space character" : "not a white-space character");

    // isupper: Checks if a character is an uppercase letter
    char ch5 = 'D';
    printf("isupper: Character '%c' is %s\n", ch5, isupper(ch5) ? "an uppercase letter" : "not an uppercase letter");

    // islower: Checks if a character is a lowercase letter
    char ch6 = 'z';
    printf("islower: Character '%c' is %s\n", ch6, islower(ch6) ? "a lowercase letter" : "not a lowercase letter");

    // toupper: Converts a lowercase letter to uppercase
    char ch7 = 'e';
    printf("toupper: Converted '%c' to '%c'\n", ch7, toupper(ch7));

    // tolower: Converts an uppercase letter to lowercase
    char ch8 = 'Q';
    printf("tolower: Converted '%c' to '%c'\n", ch8, tolower(ch8));

    return 0;
}
