#include "functions.c"

int main()
{
    /*PROBLEM 01 : Create a List, initialize it*/
    List classList;
    initList(&classList) ? printf("List initialized\n") : printf("List not initialized\n");
    system("pause");
    system("cls");

    /*PROBLEM 02 : Read students from file to populate the list then display them.
        Hint: The content is saved using the structure Student 1 entry at a time.
    */
    readStudentsFromFile("students.bin", &classList);
    displayStudentList(classList);
    system("pause");
    system("cls");

    /*PROBLEM 03 : Create a room using ClassPtr structure and initialize it.*/
    ClassPtr roomList;
    initRooms(&roomList) ? printf("Rooms initialized\n") : printf("Rooms not initialized\n");
    system("pause");
    system("cls");

    /*PROBLEM 04 : Populate the rooms with students from the list based on the
    year they have, Class code for each room is C0-0D where D is their year
    level, delete the student from the list, then display each room with class code
    and the students each have.*/
    populateRooms(&roomList, &classList);
    displayStudentsInRoom(roomList);

    return 0;
}