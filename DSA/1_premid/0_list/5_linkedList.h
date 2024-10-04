#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
} Element;

typedef struct node {
    Element elem;
    struct node *next;
} *List;

void initList(List *list){
    *list = NULL;
}

void insertLast(List *list, int data){
    List *trav;
    for (trav = list; (*trav) != NULL; trav = &(*trav)->next) {}
    List temp = (List) malloc (sizeof(struct node));
    if (temp == NULL){
        printf("ERROR IN MALLOC");
    } else {
        temp->elem.data = data;
        temp->next = NULL;
        *trav = temp;
    }
}

void insertFirst(List *list, int data){
    List temp = (List) malloc (sizeof(struct node));
    if (temp == NULL){
        printf("ERROR IN MALLOC");
    } else {
        temp->elem.data = data;
        temp->next = *list;
        *list = temp;
    }
}

void deleteElem(List *list, int data){
    List *trav;
    for (trav = list; (*trav) != NULL && (*trav)->elem.data != data; trav = &(*trav)->next) {}
    if ((*trav) != NULL){
        List temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

void printList(List list){
    List trav;
    for (trav = list; trav != NULL; trav = trav->next){
        printf("%d%s", trav->elem.data, (trav->next != NULL) ? ", ": ".\n");
    }
}


#endif