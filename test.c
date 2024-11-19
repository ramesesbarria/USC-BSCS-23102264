#include <stdio.h>
#define MAX 20

typedef struct {
    int id;
} Intruder;

typedef struct {
    Intruder intruders[MAX];
    int count;
} IntruderList;

void initList(IntruderList *list) {
    list->count = 0;
}

// Add unique intruder ID to the list if it's not already present
void addUniqueIntruder(IntruderList *list, int id) {
    // add code here
}

// Check if an intruder ID exists in the list
int isPresent(IntruderList *list, int id) {
    // add code here
    return 0; // Placeholder
}

// Delete the first occurrence of an intruder ID from the list
void deleteFirstOccurrence(IntruderList *list, int id) {
    // add code here
}

// Reset the list to clear all intruder records
void resetList(IntruderList *list) {
    // add code here
}

// Print all intruder IDs in the list
void printIntruderList(IntruderList list) {
    // add code here
}

int main() {
    IntruderList intruderList;
    initList(&intruderList);

    // Sample commands to test functionality
    addUniqueIntruder(&intruderList, 404);
    addUniqueIntruder(&intruderList, 505);
    addUniqueIntruder(&intruderList, 404); // Duplicate, should not be added
    addUniqueIntruder(&intruderList, 606);

    if (isPresent(&intruderList, 505)) {
        printf("Intruder ID 505 found.\n");
    } else {
        printf("Intruder ID 505 not found.\n");
    }

    printIntruderList(intruderList);

    deleteFirstOccurrence(&intruderList, 505);
    printIntruderList(intruderList);

    resetList(&intruderList);
    printIntruderList(intruderList);

    return 0;
}
