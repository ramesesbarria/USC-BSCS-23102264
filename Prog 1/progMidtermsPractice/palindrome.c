#include <stdio.h>
int main(){

    int decimalNum;

    printf("Enter num: ");
    scanf("%d", &decimalNum);

    int binary = 0;
    int i = 1;

    while(decimalNum > 0){
        int remainder = decimalNum % 2;
        binary += remainder * i;
        i *= 10;
        decimalNum /= 2;
    }

    printf("%d", binary);

    int reversedNum = 0;
    int orig;

    orig = binary;

    while(binary > 0){
        int lastDigit = binary % 10;
        reversedNum = reversedNum * 10 + lastDigit;
        binary /= 10;
    }

    if(reversedNum == orig){
        printf("\npalindrome");
    } else {
        printf("\nNot");
    }
    return 0;

}