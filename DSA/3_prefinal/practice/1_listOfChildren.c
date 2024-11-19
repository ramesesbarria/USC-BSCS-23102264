#include <stdio.h>
#include <stdlib.h>

#define ROOT -1
#define NE -2
#define MAX 10

typedef struct node{
    int data;
    struct node* link;
}*list;

typedef struct{
    list header[MAX];
    int root;
}tree;

void init(tree* t, int root){
    t->root = root;
    for (int i = 0; i < MAX; t->header[i++] = NULL){}
}

void insert(tree* t, int node, int parent){
    list* trav;
    for(trav = &(t->header[parent]); *trav != NULL; trav = &(*trav)->link){}
    list temp = (list) malloc (sizeof(struct node));
    if (temp != NULL){
        temp->data = node;
        temp->link = NULL;
        *trav = temp;
    }
}

void display(tree t){
    int i;
    list trav;
    for (i = 0 ; i < MAX; i++){
        printf("%d. ", i);
        for (trav = t.header[i]; trav != NULL; trav = trav->link){
            printf("%d ---> ", trav->data);
        }
        printf("NULL\n");
    }
}

int parent(tree t, int node){
    int i, parent = NE;
    list trav;
    for (i = 0; i < MAX; i++){
        for (trav = t.header[i]; trav != NULL && trav->data != node; trav = trav->link){}
        if(trav != NULL){
            parent = i;
        }
    }
    return parent;
}

int leftmost_child(tree t, int node){
    return (t.header[node] != NULL) ? t.header[node]->data : NE;
}

int rightmost_sibling(tree t, int node){
    int par = parent(t, node);
    list trav;
    if (par != NE){
        for (trav = t.header[par]; trav->link != NULL; trav = trav->link){}
    }
    return (trav != NULL) ? trav->data : NE;
}

int root(tree t){ return t.root;}

void makenull(tree* t){
    for (int i = 0; i < MAX; t->header[i++] = NULL){}
}

int main() {
    tree t;
    init(&t, 0);

    insert(&t, 1, 0);
    insert(&t, 2, 0);
    insert(&t, 3, 1);
    insert(&t, 4, 1);
    insert(&t, 5, 2);
    insert(&t, 6, 2);

    printf("Tree structure:\n");
    display(t);

    printf("\nParent of node 3: %d\n", parent(t, 3));
    printf("Leftmost child of node 1: %d\n", leftmost_child(t, 1));
    printf("Rightmost sibling of node 4: %d\n", rightmost_sibling(t, 4));
    printf("Root of the tree: %d\n", root(t));

    makenull(&t);
    printf("\nTree after makenull:\n");
    display(t);

    return 0;
}