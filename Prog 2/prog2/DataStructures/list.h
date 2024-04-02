#ifndef LIST_H
#define LIST_H

typedef struct {
    int size;
    int capacity;
    char *data;
} list;

void listImplementation();
void insert(list *l);
void Extract(list *l);
void showList(list *l);

#endif
