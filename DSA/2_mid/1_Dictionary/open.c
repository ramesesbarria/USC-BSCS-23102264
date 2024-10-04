#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node{
    int data;
    struct node* next;
} *Nodetype;

typedef enum {TRUE, FALSE} boolean;

typedef Nodetype Dictionary[MAX];

int hash(int data){
    return data % MAX;
}
void initD(Dictionary D){
    for (int i = 0; i < MAX; i++){
        D[i] = NULL;
    }
}
void dispD(Dictionary D){
    for (int i = 0; i < MAX; i++){
        printf("Row %d: ", i);
        Nodetype trav;
        for(trav = D[i]; trav != NULL; trav = trav->next){
            printf("%5d ",trav->data);
        }
        printf("\n");
    }
}
void insert(Dictionary D, int data){
    int index = hash(data);
    Nodetype *trav;
    for (trav = &D[index]; *trav != NULL; trav = &(*trav)->next){}
    if (*trav == NULL){
        Nodetype new = (Nodetype) malloc (sizeof(struct node));
        if (new != NULL){
            new->data = data;
            new->next = NULL;
            *trav = new;
        }
    }
}
void popuD(Dictionary D, int arr[], int size){
    for (int i = 0; i < size; i++){
        insert(D, arr[i]);
    }
}
void delete(Dictionary D, int data){
    int index = hash(data);
    Nodetype* trav;
    for (trav = &D[index]; *trav != NULL && (*trav)->data != data; trav = &(*trav)->next){}
    if (*trav != NULL){
        Nodetype temp = *trav;
        *trav = (*trav)->next;
        free(temp);
    }
}
boolean isMember(Dictionary D, int data){
    int index = hash(data);
    Nodetype* trav;
    for (trav = &D[index]; *trav != NULL && (*trav)->data != data; trav = &(*trav)->next){}
    return (*trav != NULL) ? TRUE : FALSE;
}

int main() {
    Dictionary D;
    initD(D);

    // Example array to populate the dictionary
    int arr[] = {12, 25, 32, 18, 5, 15, 27};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Populate the dictionary with the array elements
    popuD(D, arr, size);

    // Display the dictionary contents
    printf("Dictionary contents after insertion:\n");
    dispD(D);

    // Check for membership
    int checkData = 15;
    if (isMember(D, checkData)) {
        printf("%d is a member of the dictionary.\n", checkData);
    } else {
        printf("%d is not a member of the dictionary.\n", checkData);
    }

    // Delete an element
    delete(D, 25);
    printf("Dictionary contents after deleting 25:\n");
    dispD(D);

    // Free remaining nodes in the dictionary
    for (int i = 0; i < MAX; i++) {
        Nodetype trav = D[i];
        while (trav != NULL) {
            Nodetype temp = trav;
            trav = trav->next;
            free(temp);
        }
    }

    return 0;
}
