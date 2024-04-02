#include <stdio.h>
#include <string.h>

int main(){

    char sentence[100];
    char word[100];

    printf("Enter a sentence: ");
    scanf(" %[^\n]", sentence);

    printf("Enter a word: ");
    scanf(" %[^\n]", word);

    if (strstr(sentence, word) != NULL) {
        printf("%s is present in the sentence.", word);
    } else {
        printf("%s is not present in the sentence.", word);
    }

    return 0;

}