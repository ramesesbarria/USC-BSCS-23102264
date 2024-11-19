#include <stdio.h>
#include <stdlib.h>

#define ROOT -1
#define NE -2
#define MAX 10

typedef int tree[MAX];

tree* init(){
    tree* newTree = (tree*) malloc (sizeof(tree));
    if (newTree != NULL){
        for (int i = 0; i < MAX; i++){
            *newTree[i] = NE;
        }
    }
    return newTree;
}

void insert(int elem, int parent, tree* t){
    if (*t[elem] != NE){
        *t[elem] = parent;
    } else {
        printf("Node %d already exists in the tree.\n", elem);
    }
}

void display(tree t){
    for (int i = 0; i < MAX; i++){
        if (t[i] != NE) {
            printf("Node %d -> Parent %d\n", i, t[i]);
        }
    }
}

int parent(int node, tree t){
    return (t[node] != ROOT) ? t[node] : NE;
}

int leftmost_child(int node, tree t){
    int i;
    for (i = 0; i < MAX && t[i] != node; i++){}
    return (i < MAX) ? i : NE;
}

int right_sibling(int node, tree t){
    int i;
    for (i = node + 1; i < MAX && t[i] != t[node]; i++){}
    return (i < MAX) ? i : NE;
}

int root(tree t){
    int i;
    for (i = 0; i < MAX && t[i] != ROOT; i++){}
    return (i < MAX) ? i : NE;
}

void makenull(tree *t){
    for (int i = 0; i < MAX; *t[i++] = NE){}
}

int main() {
    tree* myTree = init();
    
    insert(0, ROOT, myTree);
    insert(1, 0, myTree);
    insert(2, 0, myTree);
    insert(3, 1, myTree);
    insert(4, 1, myTree);
    insert(5, 2, myTree);
    insert(6, 2, myTree);

    printf("Tree structure:\n");
    display(*myTree);

    int node = 3;
    printf("\nParent of node %d: %d\n", node, parent(node, *myTree));
    printf("Leftmost child of node %d: %d\n", node, leftmost_child(node, *myTree));
    printf("Right sibling of node %d: %d\n", node, right_sibling(node, *myTree));
    printf("Root of the tree: %d\n", root(*myTree));

    makenull(myTree);
    printf("\nTree after makenull:\n");
    display(*myTree);

    free(myTree);
    return 0;
}