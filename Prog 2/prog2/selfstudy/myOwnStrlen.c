#include <stdio.h>

int mystrlen(char str[]);

int main(){
    char sentence[100];
    int length;

    printf("Enter a sentence: ");
    scanf(" %[^\n]", sentence);

    length = mystrlen(sentence);

    printf("The length of the sentence is %d", length);
}
int mystrlen(char str[]){
    int length;

    for (length = 0; str[length] != '\0'; length++);

    return length;
}