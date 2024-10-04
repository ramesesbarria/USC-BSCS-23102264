//Version Four (List is a pointer to a structure containing a pointer to the 1st element of a 
//dynamic array, and variable count):

#ifndef VERSION4_H
#define VERSION4_H

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int data;
} Element;

typedef struct node {
    Element *elem;
    int count;
} *List;

void initList(List *list) {
    (*list) = (List) malloc (sizeof(struct node));
    (*list)->count = 0;
    (*list)->elem = (Element*) malloc (sizeof(Element) * MAX);
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
