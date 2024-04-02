#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void listImplementation() {
    list mylist;
    mylist.size = 0;
    mylist.capacity = 100;
    mylist.data = (char *)malloc(mylist.capacity * sizeof(char));

    if (mylist.data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int checker = 0;
    while (checker == 0) {
        switch (listSubMenu()) {
            case 1:
                insert(&mylist);
                break;
            case 2:
                Extract(&mylist);
                break;
            case 3:
                showList(&mylist);
                break;
            case 4:
                checker++;
                break;
        }
    }

    free(mylist.data);
    actionChosen();
}

void insert(list *l) {
    char input;
    if (l->size == l->capacity) {
        printf("List full\n");
    } else {
        printf("Enter a character to insert: ");
        scanf(" %c", &input);
        l->data[l->size] = input;
        l->size++;
    }
}

void Extract(list *l) {
    if (l->size == 0) {
        printf("List empty\n");
    } else {
        int index;
        printf("Enter the index to Extract: ");
        scanf("%d", &index);
        if (index < 0 || index >= l->size) {
            printf("Invalid index\n");
        } else {
            for (int i = index; i < l->size - 1; i++) {
                l->data[i] = l->data[i + 1];
            }
            l->size--;
        }
    }
}

void showList(list *l) {
    if (l->size == 0) {
        printf("List empty\n");
    } else {
        printf("The list currently contains the following: ");
        for (int i = 0; i < l->size; i++) {
            printf("%c ", l->data[i]);
        }
        printf("\n");
    }
}
