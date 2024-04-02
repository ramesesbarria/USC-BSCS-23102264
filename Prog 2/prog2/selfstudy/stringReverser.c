#include <stdio.h>
#include <string.h>

int main(){

    char string1[100];
    int length;

    printf("Enter string: ");
    scanf(" %[^\n]", string1);
    
    length = strlen(string1);

    for (int i = length - 1; i >= 0; i--){
        printf("%c", string1[i]);
    }

    return 0;
}