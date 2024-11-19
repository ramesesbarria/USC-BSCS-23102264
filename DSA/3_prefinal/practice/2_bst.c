#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}*bst, ctype;

void init(bst* t) { *t = NULL; }

void insert(bst* t, int data){
    bst temp = (bst) malloc (sizeof(ctype));
    if (temp != NULL){
        temp->data = data;
        temp->left = NULL;
        temp ->right = NULL;

        bst* trav;
        for (trav = t; *trav != NULL && (*trav)->data != data;
            trav = (*trav)->data > data ? &(*trav)->left : &(*trav)->right){}
        if (*trav == NULL){
            *trav = temp;
        } else {
            printf("Element already in the bst");
        }
        
    }
}

void populate(bst* t, int arr[], int size){
    for (int i = 0; i < size; i++){
        insert(t, arr[i]);
    }
}

void isFound(bst t, int node){
    bst trav;
    for (trav = t; trav != NULL && trav->data != node; 
        trav = (trav->data > node) ? trav->left : trav->right){}
    if (trav == NULL){
        printf("is not found");
    } else {
        printf("is found");
    }
}

void delete(bst* t, int node){
    bst *trav, *tempFor2, temp;
    for (trav = t; (*trav) != NULL && (*trav)->data != node;
            trav = (*trav)->data > node ? &(*trav)->left : &(*trav)->right){}
    if ((*trav) != NULL){
        if((*trav)->left == NULL || (*trav)->right == NULL){ // deleting a node with one or no child
            temp = *trav; 
            (*trav) = ((*trav)->left != NULL) ? (*trav)->left :(*trav)->right;
        } else {
            for(tempFor2 = &(*trav)->left; (*tempFor2)->right != NULL; tempFor2 = &(*tempFor2)->right){} 
            (*trav)->data = (*tempFor2)->data;
            temp = (*tempFor2);
            (*tempFor2) = (*tempFor2)->left;
        }
        free(temp);
    }
}

void preorder(bst T){
    if (T != NULL){
        printf("%d " , T->data);
        preorder(T->left);
        preorder(T->right);
    }
}

void inorder(bst T){
    if (T != NULL){
        inorder(T->left);
        printf("%d ", T->data);
        inorder(T->right);
    }
}

void postorder(bst T) {
    if (T != NULL) {
        postorder(T->left);
        postorder(T->right);
        printf("%d ", T->data);
    }
}

int main() {
    bst tree;
    init(&tree);

    int arr[] = {10, 5, 14, 7, 12, 18, 11, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    populate(&tree, arr, size);

    printf("Preorder traversal: ");
    preorder(tree);
    printf("\n");

    printf("Inorder traversal: ");
    inorder(tree);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(tree);
    printf("\n");

    int searchNode = 40;
    printf("Searching for %d: ", searchNode);
    isFound(tree, searchNode);
    printf("\n");

    int deleteNode = 20;
    printf("Deleting %d\n", deleteNode);
    delete(&tree, deleteNode);

    printf("Inorder traversal after deletion: ");
    inorder(tree);
    printf("\n");

    return 0;
}