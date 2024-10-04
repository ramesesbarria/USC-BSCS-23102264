//Version Two (List is a pointer to a structure containing an array and variable count):

#ifndef VERSION2_H
#define VERSION2_H

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int data;
} Element;

typedef struct node{
    Element elem[MAX];
    int count;
} *List;

void initList(List *list) {
    *list = (List) malloc (sizeof(struct node));
    (*list)->count = 0;
}


void insertLast(List list, int data) {
    if (list->count < MAX) {
        list->elem[list->count++].data = data;
    }
}

void insertFirst(List list, int data){
    if (list->count < MAX) {
        for (int i = list->count; i > 0; i--) {
            list->elem[i] = list->elem[i - 1];
        }
        list->elem[0].data = data;
        list->count++;
    }
}

void printList(List list) {
    printf("List: ");
    for (int i = 0; i < list->count; i++) {
        printf("%d%s", list->elem[i].data, (i != list->count - 1) ? ", " : ".\n");
    }
    printf("LIST NOW EMPTY\n");
}

void deleteFirstOccurrence(List list, int data) {
    int i;
    for (i = 0; i < list->count && list->elem[i].data != data; i++){}
    if (i != list->count){
        while (i != list->count){
            list->elem[i] = list->elem[i + 1];
            i++;
        }
        list->count--;
    }
}
#endif
