#include <stdio.h>

int getDigits(int number);
int power(int base, int exponent);
int decimalToBinary(int decimalNumber);
int isPalindrome(int number);

int main() {
    int number, binaryNumber;

    printf("Enter your number: ");
    scanf("%d", &number);

    binaryNumber = decimalToBinary(number);
    printf("The value of your soul is %d.\n", binaryNumber);
    
    if (isPalindrome(binaryNumber)) {
        printf("You are worthy my child.");
    } else {
        printf("Ahh, you are filty. Be gone.");
    }
}

int decimalToBinary(int decimalNumber) {
    int binaryNumber = 0;

    for (int i = 1; decimalNumber > 0; i *= 10) {
        binaryNumber += decimalNumber % 2 * i;
        decimalNumber /= 2;
    }

    return binaryNumber;
}

int isPalindrome(int number) {
    int digits = getDigits(number);
    int originalNumber = number;
    int reversedNumber = 0;

    for (int i = digits; i > 0; --i) {
        reversedNumber += number % 10 * power(10, i - 1);
        number /= 10;
    }

    if (reversedNumber == originalNumber) {
        return 1;
    } else {
        return 0;
    }
}

int getDigits(int number) {
    int digits = 0;

    while (number > 0) {
        digits += 1;
        number /= 10;
    }

    return digits;
}

int power(int base, int exponent) {
    int result = 1;

    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    
    return result;
}

