//Version Three (List is a structure containing a pointer to the 1st element of a dynamic array, 
// and variable count):


#ifndef VERSION3_H
#define VERSION3_H

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int data;
} Element;

typedef struct {
    Element *elem;
    int count;
} List;

void initList(List *list) {
    list->count = 0;
    list->elem = (Element*) malloc (sizeof(Element) * MAX);
    list->elem[0].data = 0;
}

void insertLast(List *list, int data) {
    
}

void insertFirst(List *list, int data) {

}

void printList(List list) {

}

void deleteFirstOccurrence(List *list, int data) {

}
#endif
