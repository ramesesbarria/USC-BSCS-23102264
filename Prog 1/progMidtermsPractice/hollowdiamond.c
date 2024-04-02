#include <stdio.h>
int main(){

    int size;

    printf("Enter the size of your pyramid: ");
    scanf("%d", &size);

    for(int i = 1; i <= size; i++){
        for(int j = 1; j <= size - i; j++){
            printf(" ");
        }
        for(int j = 1; j <= i; j++){
            if (j == 1 || j == i){
                printf("* ");
            } else {
                printf("  ");
            }          
        }
        printf("\n");
    }
    for(int i = size - 1; i >= 1; i--){
        for(int j = 1; j <= size - i; j++){
            printf(" ");
        }
        for(int j = 1; j <= i; j++){
            if (j == 1 || j == i){
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }    
return 0;
}
