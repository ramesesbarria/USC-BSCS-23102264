#include <stdio.h>

int main() {
    int examTotal = 0, practicalTotal = 0, taskTotal = 0;
    int exam, practical, task;
    float examAverage, practicalAverage, taskAverage;
    float finalGrade;

    printf("[PROVIDE ONLY THE PERCENTAGE EQUIVALENT OF YOUR SCORES]\n");

    for (int i = 1; i <= 2; i++) {
        printf("Enter grade for exam %d: ", i);
        while (scanf("%d", &exam) != 1 || exam < 0 || exam > 100) {
            // Clear the input buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a non-negative integer: ");
        }
        examTotal += exam;
    }

    for (int i = 1; i <= 5; i++) {
        printf("Enter grade for practical %d: ", i);
        while (scanf("%d", &practical) != 1 || practical < 0) {
            // Clear the input buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a non-negative integer: ");
        }
        practicalTotal += practical;
    }

    for (int i = 1; i <= 10; i++) {
        printf("Enter grade for task %d: ", i);
        while (scanf("%d", &task) != 1 || task < 0) {
            // Clear the input buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a non-negative integer: ");
        }
        taskTotal += task;
    }

    examAverage = (float)examTotal / 2;
    practicalAverage = (float)practicalTotal / 5;
    taskAverage = (float)taskTotal / 10;

    finalGrade = ((examAverage * 0.40) + (practicalAverage * 0.30) + (taskAverage * 0.30));

    if (finalGrade < 60){
        finalGrade = 60;
    }

    printf("\nThe average of your exams is %.2f.\n", examAverage);
    printf("The average of your practicals is %.2f\n", practicalAverage);
    printf("The average of your tasks is %.2f\n", taskAverage);
    printf("\nYour final grade is %.2f, you are: ", finalGrade);

    if (finalGrade >= 90) {
        printf("Proficient");
    } else if (finalGrade >= 80) {
        printf("Advanced");
    } else if (finalGrade >= 75) {
        printf("Average");
    } else {
        printf("Needs improvement");
    }

    return 0;
}
