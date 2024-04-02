#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 20
#define MAX_STUDS 15
#define MAX_CODE 7
#define MAX_ID 10
#define MAX_CLASS 4

typedef enum {
    FALSE, TRUE
} Boolean;

typedef struct {
    char FN[MAX_NAME];
    char LN[MAX_NAME];
    char MI;
} Name;

typedef struct {
    int month;
    int day;
    int year;
} Date;

typedef struct {
    char id[MAX_ID];
    Name name;
    Date dob;
    int age;
    int yearLevel;
    float gpa;
} Student;

typedef struct {
    Student *students;
    int numStudents;
} List;

typedef struct {
    char code[MAX_CODE];
    List studentList;
} Class;

typedef struct classNode {
    Class room;
    struct classNode *next;
} *ClassPtr;

Boolean initList(List *list);
Boolean initClass(Class *c);
Boolean initRooms(ClassPtr *R);

void readStudentsFromFile(const char *filename, List *C);

void addToRoomDeleteFromList(ClassPtr *R, List *L, int level);
Boolean addUniqueOrderedStudent(Class *c, Student student);
void insertSortedRoom(ClassPtr *R, ClassPtr newClass);
Boolean populateRooms(ClassPtr *R, List *L);

void displayStudentList(List L);
void displayStudentsInRoom(ClassPtr R);