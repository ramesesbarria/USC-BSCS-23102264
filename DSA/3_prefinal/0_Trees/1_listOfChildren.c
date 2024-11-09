/*
List Of Children Implementation of Trees

- Similar to open-hashing

*/

#include <stdio.h>
#include <stdlib.h>
#define ROOT -1
#define NE -2
#define MAX 10

typedef struct node{
    int data;
    struct node* link;
}*List;

typedef struct {
    List header[MAX];
    int root;
}Tree;

void init(Tree* T, int root){
    T->root = root;
    for(int i = 0; i < MAX; i++){
        T->header[i] = NULL;
    }
}

void insert(Tree* T, int elem, int parent){
    List* trav;
    for(trav = &(T->header[parent]); (*trav) != NULL; trav = &(*trav)->link){}
    List temp = (List) malloc (sizeof(struct node));
    if(temp != NULL){
        temp->data = elem;
        temp->link = NULL;
        *trav = temp;
    }
}

void display(Tree T){
    int i;
    List trav;
    for (i = 0; i < MAX; i++){
        printf("%d. ", i);
        for(trav = T.header[i]; trav != NULL; trav = trav->link){
            printf("%d --> ", trav->data);
        } 
        printf("NULL\n");
    }
}

int parent(int n, Tree T){
    int i, p = NE;
    List trav;
    for (i = 0; i < MAX; i++){
        for (trav = T.header[i]; trav != NULL && trav->data != n; trav = trav->link){}
        if(trav != NULL){
            p = i;
        }
    }
    return p;
}

int leftmost_child(int n, Tree T){
    return (T.header[n] != NULL) ? T.header[n]->data : NE;

}

int rightmost_sibling(int n, Tree T){
    int p = parent(n, T);
    List trav;
    if (p != NE){
        for (trav = T.header[p]; trav->link != NULL; trav = trav->link){}
    }
    return (trav != NULL) ? trav->data : NE;
}   

int root(Tree T){ return T.root; }

void MAKENULL(Tree *T){
    for (int i = 0; i < MAX; i++){
        T->header[i] = NULL;
    }
}


int main() {
    Tree T;
    
    // Initialize the tree with root node as 0
    init(&T, 0);

    // Insert nodes into the tree
    insert(&T, 1, 0);   // Insert node 1 as a child of root node 0
    insert(&T, 2, 0);   // Insert node 2 as a child of root node 0
    insert(&T, 3, 1);   // Insert node 3 as a child of node 1
    insert(&T, 4, 1);   // Insert node 4 as a child of node 1
    insert(&T, 5, 2);   // Insert node 5 as a child of node 2

    // Display the tree structure
    printf("Tree structure:\n");
    display(T);

    // Find parent of a node
    int parent_node = parent(3, T);
    printf("\nParent of node 3: %d\n", parent_node);


    // Find leftmost child of a node
    int left_child = leftmost_child(1, T);
    printf("Leftmost child of node 1: %d\n", left_child);

    // Find rightmost sibling of a node
    int right_sibling = rightmost_sibling(3, T);
    printf("Rightmost sibling of node 3: %d\n", right_sibling);
    // Find rightmost sibling of a node
    int r = rightmost_sibling(1, T);
    printf("Rightmost sibling of node 1: %d\n", r);

    // Display root node
    printf("Root of the tree: %d\n", root(T));

    // Make the tree null
    MAKENULL(&T);
    printf("\nTree after MAKENULL:\n");
    display(T);

    return 0;
}
