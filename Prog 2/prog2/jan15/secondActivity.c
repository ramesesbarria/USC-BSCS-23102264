#include <stdio.h>
int main(){

    int num;

    int array1[10] = {};

    for (int i = 0; i < 10; i++){
        printf("Num %d: ", i + 1);
        scanf("%d", &num);
        array1[i] = num;
    }

    for (int i = 0; i < 10; i++){
        if (i < 9){
            printf("%d, ", array1[i]);
        } else {
            printf("%d", array1[i]);
        }
    }

    return 0;
}