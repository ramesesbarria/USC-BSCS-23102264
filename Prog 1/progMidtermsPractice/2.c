#include <stdio.h>

int main() {
    float gpa;

    // Input GPA from the user
    printf("Enter the student's GPA: ");
    scanf("%f", &gpa);

    // Check the GPA and determine the division
    if (gpa >= 90) {
        printf("First Division\n"); //ouput
    } else if (gpa >= 80) {
        printf("Second Division\n"); //ouput
    } else if (gpa >= 75) {
        printf("Third Division\n"); //ouput
    } else {
        printf("Fourth Division\n"); //ouput
    }

    return 0;
}
