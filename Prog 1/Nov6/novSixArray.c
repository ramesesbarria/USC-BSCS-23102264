#include <stdio.h>

int main() {
    // Initialize a 2D array 'students' to store the scores of 7 students for 5 weeks.
    int* students[] = {
        (int[]){99, 42, 74, 83, 100},
        (int[]){90, 91, 72, 88, 95},
        (int[]){88, 61, 74, 89, 96},
        (int[]){61, 89, 82, 98, 93},
        (int[]){93, 73, 75, 78, 99},
        (int[]){50, 65, 92, 87, 94},
        (int[]){43, 98, 78, 56, 99}
    };

    // Print the week numbers.
    printf("         week     \n");
    printf("    ");
    for (int i = 0; i < 5; i++) {
        printf("%d  ", i);
    }
    printf("\n    ---------------\n");
     
    // Print student scores for each week.
    for (int i = 0; i < 7; i++) {
        printf("%d ", i);
        printf("|");
        printf(" ");
        for (int j = 0; j < 5; j++) {
            printf("%d ", students[i][j]);
        }
        printf("\n");
    }

    printf("    ---------------\n");

    // Calculate and print the average scores for each student.
    printf("       averages   \n");
    for (int i = 0; i < 7; i++) {
        int rowSum = 0;
        for (int j = 0; j < 5; j++) {
            rowSum += students[i][j];
        }
        double rowAvg = (double)rowSum / 5;
        printf("row %d average: %.2f\n", i, rowAvg);
    }

    // Calculate and print the average scores for each week.
    for (int j = 0; j < 5; j++) {
        int colSum = 0;
        for (int i = 0; i < 7; i++) {
            colSum += students[i][j];
        }
        double colAvg = (double)colSum / 7;
        printf("column %d average: %.2f\n", j, colAvg);
    }


    printf("---------------------------------\n");
    printf("lowest grade per student and week\n");

    for (int i = 0; i < 7; i++) {
        int lowestGrade = students[i][0];
        for (int j = 1; j < 5; j++) {
            if (students[i][j] < lowestGrade) {
                lowestGrade = students[i][j];
            }
        }
        printf("row %d: %d\n", i, lowestGrade);

    }

    for (int j = 0; j < 5; j++){
        int lowestGrade = students[0][j];
        for (int i = 1; i < 7; i++){
            if (students[i][j] < lowestGrade) {
                lowestGrade = students[i][j];
            }
        }
        printf("column %d: %d\n", j, lowestGrade);
    }


    return 0;
}
