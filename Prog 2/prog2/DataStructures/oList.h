#ifndef ORDERED_LIST_H
#define ORDERED_LIST_H

typedef struct {
    int size;
    int capacity;
    char *data;
} ordered_list;

void orderedListImplementation();
void insertOrdered(ordered_list *l);
void deleteOrdered(ordered_list *l);
void showOrderedList(ordered_list *l);

#endif
