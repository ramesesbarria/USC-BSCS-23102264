#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    char elem;
    struct node *link;
} ctype, *List;

// Initialize operations

void insertFirst(List *L, char data);
void insertLast(List *L, char data);
void InsertAfterPos(List *L, char data);
void displayList(List L);
void countList(List *L);
void deleteFirst(List *L);
void deleteChar(List *L, char data);
void findMember(List *L, char data);

int main() {
    List L = NULL;

    char chars[] = {'H', 'O', 'P', 'E'};

    int numElements = sizeof(chars) / sizeof(chars[0]);

    for (int i = 0; i < numElements; i++){
        insertLast(&L, chars[i]);
    }

    insertFirst(&L, 'A');
    InsertAfterPos(&L, 'B');
    deleteFirst(&L);
    countList(&L);
    displayList(L);
    deleteChar(&L, 'B');
    displayList(L);    
    findMember(&L, 'H');
    findMember(&L, 'E');
}

// Implement operations

void insertFirst(List *L, char data){
    List new_node = (List)malloc(sizeof(ctype));
    new_node->elem = data;
    new_node->link = *L;
    *L = new_node;
}

void insertLast(List *L, char data){
    List *p = L;
    while (*p != NULL) {
        p = &(*p)->link;
    }
    *p = (List)malloc(sizeof(ctype));
    (*p)->elem = data;
    (*p)->link = NULL;
}

void InsertAfterPos(List *L, char data){
    List *p = L;
    int choice;
    printf("Character ");
    countList(p);
    printf("Pick a number to place the character after that position\n");
    printf("Picking 0 places the character at the first position: ");
    scanf("%d", &choice);
    
    if (choice == 0){
        insertFirst(p, data); // only p since List *p is already a double pointer
    } else {
        while (choice > 0) {
            p = &(*p)->link;
            choice--;
        }
        List new_node = (List)malloc(sizeof(ctype));
        new_node->elem = data;
        new_node->link = *p;
        *p = new_node;
    }   
}

void displayList(List L) {
    List q = L; // Pointer to node traversal
    while (q != NULL) {
        printf("%c ", q->elem);
        q = q->link;
    }
    printf("\n");
}

void countList(List *L) {
    List *p = L;
    int count = 0;
    while (*p != NULL) {
        count++;
        p = &((*p)->link);
    }
    printf("Count: %d", count);
    printf("\n");
}

void deleteFirst(List *L){
    List *p = L;
    List temp = *p;
    *p = temp->link;
    free(temp);
}

void deleteChar(List *L, char data){
    List *p = L;
    while (*p != NULL && (*p)->elem != data){
        p = &((*p)->link);
    }
    List temp = *p;
    *p = temp->link;
    free(temp);
}

void findMember(List *L, char data){
    List *p = L;
    int index = 0;
    while (*p != NULL && (*p)->elem != data){
        p = &((*p)->link);
        index++;
    }
    if (*p != NULL){
        printf("%c is present in the LL list and is at index %d\n", data, index);
    }
}