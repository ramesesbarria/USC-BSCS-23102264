#include <stdio.h>
#include <string.h>

int mystrlen(char str[]);
int main(){

    char sentence[100];
    printf("Enter a sentence: ");
    scanf(" %[^\n]", sentence);

    for (int i = 0; i < mystrlen(sentence); i++){
        if (sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u'){
            sentence[i] = '_';
        }
    }

    printf("%s", sentence);


}

int mystrlen(char str[]){
    int length;

    for (length = 0; str[length] != '\0'; length++);

    return length;
}