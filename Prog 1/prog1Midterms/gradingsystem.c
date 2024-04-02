#include <stdio.h>

int main(){

    int nSubjects, nExams, bestSubject, worstSubject;
    int bestGrade = 0, worstGrade = 100, totalGrade = 0, totalGradePS = 0;
    int grade;
    

    printf("Input number of Subjects: ");
    while (scanf("%d", &nSubjects) != 1 || nSubjects < 0) {
        while (getchar() != '\n');
        printf("Input number of Subjects: ");
    }
    
    printf("Input number of Exams: ");
    while (scanf("%d", &nExams) != 1 || nExams < 0) {
        while (getchar() != '\n');
        printf("Input number of Exams: ");
    }

    for (int a = 1; a <= nSubjects; ++a){
        totalGradePS = 0;
        for (int b = 1; b <= nExams; ++b){
            printf("Input Grade for Subject %d - Exam %d : ", a, b);
            while (scanf("%d", &grade) != 1 || grade < 0 || grade > 100){
            while (getchar() != '\n');
            printf("Input Grade for Subject %d - Exam %d : ", a, b);
            }
            
            totalGradePS += grade;
            totalGrade += grade;
    
            if (totalGradePS > bestGrade){
                bestGrade = totalGradePS;
                bestSubject = a;
            }
    
            if (totalGradePS < worstGrade || bestSubject == worstSubject){
                worstGrade = totalGradePS;
                worstSubject = a;
            }
    
            if (totalGradePS == 0){
                worstSubject = 1;
            }
            
        }
    }

    int tExams = nSubjects * nExams;   
    int gAverage = totalGrade / tExams;
    printf("\n\nAverage Grade for %d Exams : %d\n", tExams, gAverage);

    if (gAverage == 0){
        printf("\nNo Best Subject\n");
        printf("Worst Subject: Subject %d\n", worstSubject);
        printf("\nFailed this Semester");
    }

    if (gAverage > 75){
        printf("\nBest Subject: Subject %d\n", bestSubject);
        printf("Worst Subject: Subject %d\n", worstSubject);
        printf("\nPassed this Semester");
    }

    if ((gAverage <= 75) && (gAverage > 0)){
        printf("\nBest Subject: Subject %d\n", bestSubject);
        printf("Worst Subject: Subject %d\n", worstSubject);
        printf("\nFailed this Semester");
    }
    return 0;
}