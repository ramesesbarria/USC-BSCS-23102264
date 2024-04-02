#include "header.h"

//HELPER FUNCTIONS
void printLine()
{
    printf("---------------------------------------------------------------------------------------\n");
}

Name createName(char FN[], char LN[], char MI)
{
    Name name;

    strcpy(name.FN, FN);
    strcpy(name.LN, LN);
    name.MI = MI;

    return name;
}

Date createDate(int month, int day, int year)
{
    Date date;

    date.month = month;
    date.day = day;
    date.year = year;

    return date;
}

Student createStudent(Name name, Date birthDate, char id[], float gpa, int yearLvl, int age)
{
    Student student;

    strcpy(student.id, id);
    student.name = name;
    student.dob = birthDate;
    student.gpa = gpa;
    student.yearLevel = yearLvl;
    student.age = age;

    return student;
}

//EXAM FUNCTIONS
void readStudentsFromFile(const char *filename, List *C)
{
    //INSERT CODE HERE
}

void displayStudentList(List L)
{
    /*Format:
        printf("%-10s | %-15s %-5s %-10s | %-5s | %-10s | %-5s | %-10s \n", 
        "ID", "First Name", "MI", "Last Name", "Age", "DOB", "GPA", "Year Level");
    */
}

Boolean initList(List *list)
{
    Boolean success;

    //INSERT CODE HERE

    return success;
}

Boolean initClass(Class *class)
{
    Boolean success;

    //INSERT CODE HERE

    return success;
}

Boolean initRooms(ClassPtr *R)
{
    Boolean success;

    //INSERT CODE HERE

    return success;
}

Boolean addUniqueOrderedStudent(Class *c, Student student)
{
    Boolean success = FALSE;

    //INSERT CODE HERE

    return success;
}

void addToRoomDeleteFromList(ClassPtr *R, List *L, int level)
{
    int j;

    //INSERT CODE HERE
}

void insertSortedRoom(ClassPtr *R, ClassPtr newClass)
{
    //INSERT CODE HERE
}

Boolean populateRooms(ClassPtr *R, List *L)
{
    Boolean success;

    //INSERT CODE HERE

    return success;
}

void displayStudentsInRoom(ClassPtr R)
{
    //INSERT CODE HERE
}