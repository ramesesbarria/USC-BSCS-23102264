#include <stdio.h>

int getNum();

int main(){

    int a = getNum();
    int b = getNum();
    int c = getNum();

        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        if (b > c) {
            int temp = b;
            b = c;
            c = temp;
        }

        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        printf("%d, %d, %d", a, b, c);

        return 0;
}

int getNum(){

        int input;
    
            printf("Enter num: ");
            scanf("%d", &input);
            
    return input;
}