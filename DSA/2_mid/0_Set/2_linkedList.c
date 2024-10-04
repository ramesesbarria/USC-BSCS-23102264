#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} *Set;

void populateSet(Set *S);
void insert(Set *S, int data);
void printSet(Set S);
Set Union(Set A, Set B);
Set Intersection(Set A, Set B);
Set Difference(Set A, Set B);

int main() {

    Set A = NULL;
    Set B = NULL;

    populateSet(&A);
    populateSet(&B);

    printf("Set A: ");
    printSet(A);

    printf("Set B: ");
    printSet(B);

    Set U = Union(A, B);
    printf("\nUnion: ");
    printSet(U);

    Set I = Intersection(A, B);
    printf("Intersection: ");
    printSet(I);

    Set D = Difference(A, B);
    printf("(A - B): ");
    printSet(D);

    D = Difference(B, A);
    printf("(B - A): ");
    printSet(D);

    return 0;
}

void populateSet(Set *S){
    int size;
    printf("Enter size: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++){
        int data;
        printf("Element %d: ", i);
        scanf("%d", &data);
        insert(S, data);
    }
    printf("\n");
}

void insert(Set *S, int data) {
    Set *trav = S;
    for(; *trav != NULL && (*trav)->data != data; trav = &(*trav)->next) {}
    if(*trav == NULL) {
        Set temp = (Set) malloc(sizeof(struct node));
        if(temp != NULL) {
            temp->data = data;
            temp->next = NULL;
            *trav = temp;
        }
    }
}

void printSet(Set S) {
    for(Set curr = S; curr != NULL; curr = curr->next) {
        printf("%d ", curr->data);
    }

    printf("\n");
}

Set Union(Set A, Set B){
    Set U = NULL;
    Set *trav = &U;

    for (Set curr = A; curr != NULL; curr = curr->next){
        insert(&U, curr->data);
    }

    for (Set curr = B; curr != NULL; curr = curr->next){
        insert(&U, curr->data);
    }
    return U;
}
Set Intersection(Set A, Set B){
    Set I = NULL;
    Set *trav = &I;

    for (Set currA = A; currA != NULL; currA = currA->next){
        Set currB;
        for (currB = B; currB != NULL && currA->data != currB->data; currB = currB->next){}
        if(currB != NULL){
            Set temp = (Set) malloc (sizeof(struct node));
            insert(&I, currA->data);
        }
    }
    return I;
}
Set Difference(Set A, Set B){
    Set D = NULL;
    Set *trav = &A;

    for (Set currA = A; currA != NULL; currA = currA->next){
        Set currB;
        for (currB = B; currB != NULL && currA->data != currB->data; currB = currB->next){}
        if(currB == NULL){
            Set temp = (Set) malloc (sizeof(struct node));
            insert(&D, currA->data);
        }
    }
    return D;
}