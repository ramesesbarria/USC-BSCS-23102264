#include <stdio.h>
#include <stdlib.h>
#include "set.h"

void setImplementation() {
    Set mySet;
    mySet.size = 0;
    mySet.capacity = 100;
    mySet.data = (char *)malloc(mySet.capacity * sizeof(char));

    if (mySet.data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int checker = 0;
    while (checker == 0) {
        switch (setSubMenu()) {
            case 1:
                add(&mySet);
                break;
            case 2:
                find(&mySet);
                break;
            case 3:
                showSet(&mySet);
                break;
            case 4:
                checker++;
                break;
        }
    }

    free(mySet.data);
    actionChosen();
}


void add(Set *set) {
    char input;
    printf("Enter an input: ");
    scanf(" %c", &input);
    int index = contains(set, input);
    if (index == -1) {
        set->data[set->size++] = input;
    } else {
        printf("Element already exists in the set.\n");
    }
}

int contains(Set *set, char element) {
    for (int i = 0; i < set->size; i++) {
        if (set->data[i] == element) {
            return i;
        }
    }
    return -1;
}

void showSet(Set *set) {
    printf("The set currently contains the following: ");
    for (int i = 0; i < set->size; i++) {
        printf("%c ", set->data[i]);
    }
    printf("\n");
}

void find(Set *set) {
    char element;
    printf("Enter an element to find: ");
    scanf(" %c", &element);
    int index = contains(set, element);
    if (index != -1) {
        printf("Element is present in the set.\n");
    } else {
        printf("Element is not present in the set.\n");
        char choice;
        printf("Would you like to add this to the set? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            set->data[set->size++] = element;
        }
    }
}
