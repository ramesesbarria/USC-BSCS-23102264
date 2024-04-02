#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char string[100];

    printf("Enter a string: ");
    scanf("%[^\n]", string);

    char modified[100];
    int j = 0;
    int length = strlen(string);
    
    for (int i = 0; i < length + 1; i++){
        if ((int) string[i] != 32){
            modified[j] = string[i];
            j++;
        }
    }    
   
    printf("Modified string: %s", modified);
    
}