#include <stdio.h>
#include <stdlib.h>
#include "oList.h"

void orderedListImplementation() {
    ordered_list mylist;
    mylist.size = 0;
    mylist.capacity = 100;
    mylist.data = (char *)malloc(mylist.capacity * sizeof(char));

    if (mylist.data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int checker = 0;
    while (checker == 0) {
        switch (oListSubMenu()) {
            case 1:
                insertOrdered(&mylist);
                break;
            case 2:
                deleteOrdered(&mylist);
                break;
            case 3:
                showOrderedList(&mylist);
                break;
            case 4:
                checker++;
                break;
        }
    }

    free(mylist.data);
    actionChosen();
}

void insertOrdered(ordered_list *l) {
    char input;
    if (l->size == l->capacity) {
        printf("List full\n");
    } else {
        printf("Enter a character to insert: ");
        scanf(" %c", &input);
        int i;
        for (i = l->size - 1; i >= 0 && l->data[i] > input; i--) {
            l->data[i + 1] = l->data[i];
        }
        l->data[i + 1] = input;
        l->size++;
    }
}

void deleteOrdered(ordered_list *l) {
    if (l->size == 0) {
        printf("List empty\n");
    } else {
        char input;
        printf("Enter a character to delete: ");
        scanf(" %c", &input);
        int i, found = 0;
        for (i = 0; i < l->size; i++) {
            if (l->data[i] == input) {
                found = 1;
                break;
            }
        }
        if (found) {
            for (int j = i; j < l->size - 1; j++) {
                l->data[j] = l->data[j + 1];
            }
            l->size--;
        } else {
            printf("Element not found\n");
        }
    }
}

void showOrderedList(ordered_list *l) {
    if (l->size == 0) {
        printf("List empty\n");
    } else {
        printf("The ordered list currently contains the following: ");
        for (int i = 0; i < l->size; i++) {
            printf("%c ", l->data[i]);
        }
        printf("\n");
    }
}
