#ifndef SET_H
#define SET_H

typedef struct {
    char *data;
    int size;
    int capacity;
} Set;

void setImplementation();
void add(Set *set);
int contains(Set *set, char element);
void showSet(Set *set);
void find(Set *set);

#endif
