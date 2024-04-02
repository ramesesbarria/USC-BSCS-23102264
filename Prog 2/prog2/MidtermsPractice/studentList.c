#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct{
	char fName[20];
	char lName[20];
}name;
 
typedef struct{
	char subjectName[20];
	int grade;
}subjectGrade;
 
typedef struct{
	int idNum;
	name studentName;
	char course[10];
	subjectGrade studentGrade[3];
}studentInfo;
 
typedef struct{
	studentInfo *studentList;
	int count;
}classRecord;
 
typedef struct{ 
	classRecord classList;
	classRecord passersList;
}teacherRecord;
 
studentInfo addNewStudent(char [],char[],char[],int,char[],int,char[],int,char[],int);
void mainMenu(teacherRecord *);
void insertFront(teacherRecord *);
void insertLast(teacherRecord *);
void insertSorted(teacherRecord *);
void deleteFirst(teacherRecord *);
void deleteLast(teacherRecord *);
void deleteItem(teacherRecord *);
void updateGrade(teacherRecord *);
void findStudent(teacherRecord *);
void printWholeRecord(teacherRecord *);
void printPassedRecord(teacherRecord *);
void populate(teacherRecord *);
void passers(teacherRecord *);

// Tasks:

// 1. Populate classList inside teacherRecord
// 2. Sort all students with 80+ avg and add them into passersList
// 3. Implement insert front, insert last, insert sorted, delete front, delete last, delete item
// 4. implement update grades
// 5. implement find student using id number
// extra. print whole record and passers record
 
int main(){

    // task 1

    teacherRecord tRecord;

    populate(&tRecord);

    // task 2

    passers(&tRecord);

    // task 3 onwards

    mainMenu(&tRecord);

    return 0;
}
 

studentInfo addNewStudent(char fName[],char lName[],char courseName[],int idNum,char sub1[],int sub1Grade,char sub2[],int sub2Grade,char sub3[],int sub3Grade){
 
	studentInfo newStudent;
 
	newStudent.idNum=idNum;
	strcpy(newStudent.studentName.fName,fName);
	strcpy(newStudent.studentName.lName,lName);
	strcpy(newStudent.course,courseName);
 
	strcpy(newStudent.studentGrade[0].subjectName,sub1);
	newStudent.studentGrade[0].grade=sub1Grade;
 
	strcpy(newStudent.studentGrade[1].subjectName,sub2);
	newStudent.studentGrade[1].grade=sub2Grade;
 
	strcpy(newStudent.studentGrade[2].subjectName,sub3);
	newStudent.studentGrade[2].grade=sub3Grade;
 
	return newStudent;

}

void populate(teacherRecord *tRecord) {
    char fName[20], lName[20];
    int idNum;
    char course[10];
    char s1[20], s2[20], s3[20];
    int g1, g2, g3;

    printf("Enter the amount of students in your class [max: 35]:\n");
    scanf("%d", &tRecord->classList.count);

    tRecord->classList.studentList = (studentInfo*) malloc(sizeof(studentInfo) * tRecord->classList.count);

    for (int i = 0; i < tRecord->classList.count; i++) {
        printf("- Enter student %d's details -\n", i + 1);

        printf("Full name: ");
        scanf("%s %s", fName, lName);

        printf("Course: ");
        scanf("%s", course);

        printf("Id Number: ");
        scanf("%d", &idNum);

        printf("Subject 1: ");
        scanf("%s", s1);
        printf("Grade 1: ");
        scanf("%d", &g1);

        printf("Subject 2: ");
        scanf("%s", s2);
        printf("Grade 2: ");
        scanf("%d", &g2);

        printf("Subject 3: ");
        scanf("%s", s3);
        printf("Grade 3: ");
        scanf("%d", &g3);

        tRecord->classList.studentList[i] = addNewStudent(fName, lName, course, idNum, s1, g1, s2, g2, s3, g3);
    }
}

void passers(teacherRecord *tRecord) {
    tRecord->passersList.studentList = (studentInfo*) malloc(sizeof(studentInfo) * tRecord->classList.count);

    tRecord->passersList.count = 0;
    for (int i = 0; i < tRecord->classList.count; i++) {
        int gradeSum = tRecord->classList.studentList[i].studentGrade[0].grade + tRecord->classList.studentList[i].studentGrade[1].grade + tRecord->classList.studentList[i].studentGrade[2].grade;
        int average = gradeSum / 3;

        if (average > 80) {
            tRecord->passersList.studentList[tRecord->passersList.count] = tRecord->classList.studentList[i];
            tRecord->passersList.count++;
        }
    }
}

void mainMenu(teacherRecord *tRecord){
    int choice;
    do {

        printf("\nClass list manipulation menu\n");
        printf("----------------------------\n");
        printf("[1] Insert student at the front\n");
        printf("[2] Insert student at the end\n");
        printf("[3] Insert student in sorted order\n");
        printf("[4] Delete student at the front\n");
        printf("[5] Delete student at the end\n");
        printf("[6] Delete a specific student\n");
        printf("[7] Update student grades\n");
        printf("[8] Find a student by ID\n");
        printf("[9] Print the entire class record\n");
        printf("[10] Print the passed student record\n");
        printf("[11] Exit\n");


        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertFront(tRecord);
                break;
            case 2:
                insertLast(tRecord);
                break;
            case 3:
                insertSorted(tRecord);
                break;
            case 4:
                deleteFirst(tRecord);
                break;
            case 5:
                deleteLast(tRecord);
                break;
            case 6:
                deleteItem(tRecord);
                break;
            case 7:
                updateGrade(tRecord);
                break;
            case 8:
                findStudent(tRecord);
                break;
            case 9:
                printWholeRecord(tRecord);
                break;
            case 10:
                printPassedRecord(tRecord);
                break;
            case 11:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 11);
}

void insertFront(teacherRecord *tRecord) {

    for (int i = tRecord->classList.count - 1; i >= 0; i--) {
        tRecord->classList.studentList[i + 1] = tRecord->classList.studentList[i];
    }

    char fName[20], lName[20];
    int idNum;
    char course[10];
    char s1[20], s2[20], s3[20];
    int g1, g2, g3;
    printf("Note: this manipulates the general student list\n");
    printf("- Enter student's details -\n");

    printf("Full name: ");
    scanf("%s %s", fName, lName);

    printf("Course: ");
    scanf("%s", course);

    printf("Id Number: ");
    scanf("%d", &idNum);

    printf("Subject 1: ");
    scanf("%s", s1);
    printf("Grade 1: ");
    scanf("%d", &g1);

    printf("Subject 2: ");
    scanf("%s", s2);
    printf("Grade 2: ");
    scanf("%d", &g2);

    printf("Subject 3: ");
    scanf("%s", s3);
    printf("Grade 3: ");
    scanf("%d", &g3);

    tRecord->classList.studentList[0] = addNewStudent(fName, lName, course, idNum, s1, g1, s2, g2, s3, g3);
    tRecord->classList.count++;
}

void insertLast(teacherRecord *tRecord) {

    char fName[20], lName[20];
    int idNum;
    char course[10];
    char s1[20], s2[20], s3[20];
    int g1, g2, g3;
    if (tRecord->classList.count < 35){  

        printf("Note: this manipulates the general student list\n");
        printf("- Enter student's details -\n");

        printf("Full name: ");
        scanf("%s %s", fName, lName);

        printf("Course: ");
        scanf("%s", course);

        printf("Id Number: ");
        scanf("%d", &idNum);

        printf("Subject 1: ");
        scanf("%s", s1);
        printf("Grade 1: ");
        scanf("%d", &g1);

        printf("Subject 2: ");
        scanf("%s", s2);
        printf("Grade 2: ");
        scanf("%d", &g2);

        printf("Subject 3: ");
        scanf("%s", s3);
        printf("Grade 3: ");
        scanf("%d", &g3);

        tRecord->classList.studentList[tRecord->classList.count] = addNewStudent(fName, lName, course, idNum, s1, g1, s2, g2, s3, g3);
        tRecord->classList.count++; 
    } else {
        printf("Class list is full\n");
    }
}


void insertSorted(teacherRecord *tRecord) {
    studentInfo newStudent;

    printf("Note: This sorts using the ID number\n");
    printf("- Enter student's details -\n");

    printf("Full name: ");
    scanf("%s %s", newStudent.studentName.fName, newStudent.studentName.lName);

    printf("Course: ");
    scanf("%s", newStudent.course);

    printf("Id Number: ");
    scanf("%d", &newStudent.idNum);

    printf("Subject 1: ");
    scanf("%s", newStudent.studentGrade[0].subjectName);
    printf("Grade 1: ");
    scanf("%d", &newStudent.studentGrade[0].grade);

    printf("Subject 2: ");
    scanf("%s", newStudent.studentGrade[1].subjectName);
    printf("Grade 2: ");
    scanf("%d", &newStudent.studentGrade[1].grade);

    printf("Subject 3: ");
    scanf("%s", newStudent.studentGrade[2].subjectName);
    printf("Grade 3: ");
    scanf("%d", &newStudent.studentGrade[2].grade);

    int i = tRecord->classList.count - 1;
    while (i >= 0 && tRecord->classList.studentList[i].idNum > newStudent.idNum) {
        tRecord->classList.studentList[i + 1] = tRecord->classList.studentList[i];
        i--;
    }

    tRecord->classList.studentList[i + 1] = newStudent;
    tRecord->classList.count++;
}

void deleteFirst(teacherRecord *tRecord) {
    if (tRecord->classList.count > 0) {
        for (int i = 0; i < tRecord->classList.count - 1; i++) {
            tRecord->classList.studentList[i] = tRecord->classList.studentList[i + 1];
        }
        tRecord->classList.count--;
    } else {
        printf("Class list is empty\n");
    }
}

void deleteLast(teacherRecord *tRecord) {
    if (tRecord->classList.count > 0) {
        tRecord->classList.count--;
    } else {
        printf("Class list is empty\n");
    }
}

void deleteItem(teacherRecord *tRecord) {
    int idNum;
    printf("Note: This deletes using the ID number\n");
    printf("Enter student's ID number to delete: ");
    scanf("%d", &idNum);

    int foundIndex = -1;
    for (int i = 0; i < tRecord->classList.count; i++) {
        if (tRecord->classList.studentList[i].idNum == idNum) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        for (int i = foundIndex; i < tRecord->classList.count - 1; i++) {
            tRecord->classList.studentList[i] = tRecord->classList.studentList[i + 1];
        }
        tRecord->classList.count--;
        printf("Student with ID number %d deleted successfully.\n", idNum);
    } else {
        printf("Student with ID number %d not found.\n", idNum);
    }
}

void updateGrade(teacherRecord *tRecord) {
    int idNum;
    printf("Enter student's ID number to update grades: ");
    scanf("%d", &idNum);

    int foundIndex = -1;
    for (int i = 0; i < tRecord->classList.count; i++) {
        if (tRecord->classList.studentList[i].idNum == idNum) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        printf("Enter new grades for student %s %s:\n", tRecord->classList.studentList[foundIndex].studentName.fName, tRecord->classList.studentList[foundIndex].studentName.lName);
        for (int i = 0; i < 3; i++) {
            printf("Grade %d: ", i + 1);
            scanf("%d", &tRecord->classList.studentList[foundIndex].studentGrade[i].grade);
        }
        printf("Grades updated successfully for student with ID number %d.\n", idNum);
    } else {
        printf("Student with ID number %d not found.\n", idNum);
    }
}

void findStudent(teacherRecord *tRecord) {
    char fName[20], lName[20];
    printf("Enter student's first name: ");
    scanf("%s", fName);
    printf("Enter student's last name: ");
    scanf("%s", lName);

    int foundIndex = -1;
    for (int i = 0; i < tRecord->classList.count; i++) {
        if (strcmp(tRecord->classList.studentList[i].studentName.fName, fName) == 0 && strcmp(tRecord->classList.studentList[i].studentName.lName, lName) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        printf("Student found:\n");
        printf("ID Number: %d\n", tRecord->classList.studentList[foundIndex].idNum);
        printf("Course: %s\n", tRecord->classList.studentList[foundIndex].course);
        printf("Grades:\n");
        for (int i = 0; i < 3; i++) {
            printf("Subject %d: %s, Grade: %d\n", i + 1, tRecord->classList.studentList[foundIndex].studentGrade[i].subjectName, tRecord->classList.studentList[foundIndex].studentGrade[i].grade);
        }
    } else {
        printf("Student with name %s %s not found.\n", fName, lName);
    }
}

void printWholeRecord(teacherRecord *tRecord) {
    printf("Class List:\n");
    for (int i = 0; i < tRecord->classList.count; i++) {
        printf("Student %d:\n", i + 1);
        printf("ID Number: %d\n", tRecord->classList.studentList[i].idNum);
        printf("Name: %s %s\n", tRecord->classList.studentList[i].studentName.fName, tRecord->classList.studentList[i].studentName.lName);
        printf("Course: %s\n", tRecord->classList.studentList[i].course);
        printf("Grades:\n");
        for (int j = 0; j < 3; j++) {
            printf("Subject %d: %s, Grade: %d\n", j + 1, tRecord->classList.studentList[i].studentGrade[j].subjectName, tRecord->classList.studentList[i].studentGrade[j].grade);
        }
        printf("\n");
    }
}

void printPassedRecord(teacherRecord *tRecord) {
    printf("Students who passed:\n");
    for (int i = 0; i < tRecord->passersList.count; i++) {
        printf("%s %s\n", tRecord->passersList.studentList[i].studentName.fName, tRecord->classList.studentList[i].studentName.lName);
    }
}