#include <stdio.h>
#include <string.h>

int main(){

    char sentence1[100];
    char sentence2[100];

    printf("Enter sentence one: ");
    scanf(" %[^\n]", sentence1);

    printf("Enter sentence two: ");
    scanf(" %[^\n]", sentence2);

    // if (strstr(sentence1, sentence2) != NULL) {
    //     printf("The two sentences are the same.");
    // } else {
    //     printf("The two sentences are not the same.");
    // }

    // return 0;

    int isSame = 0;

    for(int i = 0; sentence1[i] != '\0' && sentence2[i] != '\0'; i++){
        if(sentence1[i] != sentence2[i]){
            isSame = 0;
        }
    }


}