#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
    char fname[12];
    char lname[12];
    char mname;
} name;

typedef struct {
    int idNumber;
    int midtermsGrade;
} grade;

typedef struct {
    name studentName;
    grade studentGrade;
} details;

typedef struct node {
    details studentDetails;
    struct node* next;
} *studentList;

void initList(studentList* list){
    (*list) = NULL;
}

void insertLast(studentList* list, details info){
    studentList newNode = (studentList) malloc (sizeof(struct node));
    if (newNode != NULL){
        studentList* trav;
        for(trav = list; (*trav) != NULL; trav = &(*trav)->next){}
        newNode->studentDetails = info;
        newNode->next = NULL;
        (*trav) = newNode;
    }
}

void insertFirst(studentList* list, details info){
    studentList newNode = (studentList) malloc (sizeof(struct node));
    if (newNode != NULL){
        newNode->studentDetails = info;
        newNode->next = *list;
        *list = newNode;
    }
}

void deleteFirst(studentList* list){
    studentList temp = *list;
    *list = temp->next;
    free(temp);
}

void deleteLast(studentList* list){
    studentList* trav;
    for(trav = list; (*trav) != NULL && (*trav)->next != NULL; trav = &(*trav)->next){}
    (*trav) = NULL;
}

void deleteID(studentList* list, int ID){
    studentList* trav;
    for(trav = list; (*trav) != NULL && ID != (*trav)->studentDetails.studentGrade.idNumber; trav = &(*trav)->next){}
    if((*trav) != NULL){
        studentList temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

void displayList(studentList list){
    studentList trav;
    printf("|--NAME ID GRADE--|\n");
    for (trav = list; trav != NULL; trav = trav->next){
        printf("%s : ", trav->studentDetails.studentName.lname);
        printf("%d : ", trav->studentDetails.studentGrade.idNumber);
        printf(" %d\n", trav->studentDetails.studentGrade.midtermsGrade);
    } 
    printf("|---END OF LIST---|\n\n");
}

int main(){

    studentList blockA;
    initList(&blockA);

    insertLast(&blockA, (details) {{"John", "Doe", 'A'}, {12345, 85}});
    insertLast(&blockA, (details) {{"Nash", "Steve", 'A'}, {12346, 100}});
    insertLast(&blockA, (details) {{"Jaeger", "Eren", 'A'}, {12347, 99}});
    insertFirst(&blockA, (details) {{"Jaeger", "Griesha", 'A'}, {12348, 99}});
    displayList(blockA);

    deleteFirst(&blockA);
    displayList(blockA);

    deleteLast(&blockA);
    displayList(blockA);

    deleteID(&blockA, 12346);
    displayList(blockA);
}