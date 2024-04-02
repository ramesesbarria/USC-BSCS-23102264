#include <stdio.h>
int main(){

    int size;

    printf("Enter size: ");
    scanf("%d", &size);

    for(int i = 1; i <= size; i++){
        for(int j = 1; j <= size; j++){
            if(j <= size - i){
                printf(" - ");
            }
            if(j == size - i + 1){
                printf(" O ");
            }
            if(j > size - i + 1){
                printf(" - ");
            }
        }
    printf("\n");
    }
return 0;
}


