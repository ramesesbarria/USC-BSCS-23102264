/*
    I PREFER THIS CODE
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 0X5

typedef int Dictionary[MAX];

typedef enum {
    EMPTY = -1,
    DELETED = -2
} Status;

void initDict(Dictionary D);
int hash(int data);
void insert(Dictionary D, int data);
void delete(Dictionary D, int data);
bool isMember(Dictionary D, int data);
void printDict(Dictionary D);

int main() {
    Dictionary D;
    initDict(D);

    // Insert elements into the dictionary
    printf("Inserting elements: 5, 10, 15, 20, 25\n");
    insert(D, 5);
    insert(D, 10);
    insert(D, 15);
    insert(D, 20);
    insert(D, 25);

    // Print the dictionary
    printf("\nCurrent Dictionary:\n");
    printDict(D);

    // Check membership
    printf("\nChecking membership for 10 and 30:\n");
    printf("Is 10 a member? %s\n", isMember(D, 10) ? "Yes" : "No");
    printf("Is 30 a member? %s\n", isMember(D, 30) ? "Yes" : "No");

    // Delete an element
    printf("\nDeleting element 10\n");
    delete(D, 10);
    
    // Print the dictionary after deletion
    printf("\nCurrent Dictionary after deletion:\n");
    printDict(D);

    // Check membership again
    printf("\nChecking membership for 10 after deletion:\n");
    printf("Is 10 a member? %s\n", isMember(D, 10) ? "Yes" : "No");

    return 0;
}



void initDict(Dictionary D) {
    for(int i = 0; i < MAX; i++) {
        D[i] = EMPTY;
    }
}

int hash(int data) {
    return data % MAX;
}

void insert(Dictionary D, int data) {
    int temp = hash(data);
    int founddeleted = -1;
    int stop = (temp + MAX - 1) % MAX;

    int i;
    for(i = temp; i != stop && D[i] != EMPTY && D[i] != data; i = (i + 1) % MAX) { // to look for empty/deleted indexes while also checking for uniqueness of data
        if(founddeleted == -1 && D[i] == DELETED) {
            founddeleted = i;
        }
    }
    if(D[i] != data && D[i] == EMPTY) {
        D[(founddeleted == -1) ? i : founddeleted] = data;
    }
}

void delete(Dictionary D, int data) {
    int temp = hash(data);

    int stop = (temp + MAX - 1) % MAX;
    int i;

    for(i = temp; i != stop && i != EMPTY && D[i]!= data; i = (i + 1) % MAX) {}

    if(D[i] == data) {
        D[i] = DELETED;
    }
}

bool isMember(Dictionary D, int data) {
    int temp = hash(data);

    int stop = (temp + MAX - 1) % MAX;
    int i;

    for(i = temp; i != stop && i != EMPTY && D[i]!= data; i = (i + 1) % MAX) {}    

    return (D[i] == data) ? true : false;
}

void printDict(Dictionary D) {
    for(int i = 0; i < MAX; i++) {
        printf("Index %d: ", i);
        if(D[i] == EMPTY) {
            printf("EMPTY");
        }
        else if(D[i] == DELETED) {
            printf("DELETED");
        }
        else {
            printf("%d", D[i]);
        }

        printf("\n");
    }
}