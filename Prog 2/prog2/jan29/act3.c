#include <stdio.h>

void printer(int*);
int main(){

    int array1[5], element;
    int* a = &array1;

    for(int i = 0; i < 5; i++){
        printf("Enter element %d: ",i+1);
        scanf("%d", a++);
        //*(a + i) = element;
    }
    a -= 5;
    printer(a);
    return 0;
}

void printer(int* a){

    for (int i = 0; i < 5; i++){
        printf("Element [%d]=%d\n", i, *(a + i));
    }
    
}