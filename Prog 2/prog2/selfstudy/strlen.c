#include <stdio.h>
#include <string.h>

int main(){

    char string1[100];
    int length;

    scanf(" %[^\n]", string1);
    
    length = strlen(string1);
    printf("%d", length);

    return 0;
}