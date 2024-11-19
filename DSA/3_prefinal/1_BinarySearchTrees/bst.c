#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right; 
} *BST, ctype;

void initBST(BST *T){
    *T = NULL;
}

void insertBST(BST *T, int data){
    BST temp = (BST) malloc (sizeof(ctype));
    if (temp != NULL){
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;

        BST *trav;

        for (trav = T; (*trav) != NULL && (*trav)->data != data;
                trav = (*trav)->data > data ? &(*trav)->left : &(*trav)->right){}
        
        if (*trav == NULL){
            *trav = temp;
        } else {
            printf("Element already in BST");
        }
    }
}

void populateBST(BST *T, int arr[], int size){
    for (int i = 0; i < size; i++){
        insertBST(T, arr[i]);
    }
}

void isFound(BST T, int x){
    BST trav;

    for(trav = T; trav != NULL && trav->data != x;
            trav = (trav->data > x ? trav->left :trav->right)){}
    if (trav == NULL){
        printf("Element is not a member");
    } else {
        printf("Element is a member");
    }
}

bool isFoundRecursion(BST T, int x){
    if (T == NULL) return false;
    if (T->data == x) return true;

    return (T->data < x) ? isFoundRecursion(T->right, x) : isFoundRecursion(T->left, x);
}

void delete(BST *T, int elem){
    BST *trav, *tempFor2, temp;
    for (trav = T; (*trav) != NULL && (*trav)->data != elem;
            trav = ((*trav)->data > elem ? &(*trav)->left : &(*trav)->right)){}
    
    if ((*trav) != NULL){
        if((*trav)->left == NULL && (*trav)->right == NULL){
            // deleting a node with no children
            temp = *trav;
            *trav = NULL;
        } else if ((*trav)->left != NULL && (*trav)->right != NULL){
            // deleting a node with 2 children
            for(tempFor2 = &(*trav)->left; (*tempFor2)->right != NULL; tempFor2 = &(*tempFor2)->right){}
            (*trav)->data = (*tempFor2)->data;
            temp = (*tempFor2);
            (*tempFor2) = (*tempFor2)->left;
        } else {
            // deleting a node with 1 children
            temp = (*trav);
            (*trav) = ((*trav)->left != NULL) ? (*trav)->left : (*trav)->right;
        }
        free(temp);
    }
}

void preorder(BST T){
    if (T != NULL){
        printf("%d " , T->data);
        preorder(T->left);
        preorder(T->right);
    }
}

void inorder(BST T){
    if (T != NULL){
        inorder(T->left);
        printf("%d ", T->data);
        inorder(T->right);
    }
}

void postorder(BST T) {
    if (T != NULL) {
        postorder(T->left);
        postorder(T->right);
        printf("%d ", T->data);
    }
}

void displayNodes(BST T) {
    if (T != NULL) {
        printf("node: %d (LC %d RC %d)\n", 
               T->data, 
               T->left ? T->left->data : -1, 
               T->right ? T->right->data : -1);
        displayNodes(T->left);
        displayNodes(T->right);
    }
}

int main() {
    BST tree;
    initBST(&tree);

    int elements[] = {7, 3, 9, 4, 2, 10};
    int size = sizeof(elements) / sizeof(elements[0]);

    populateBST(&tree, elements, size);

    printf("Display all nodes:\n");
    displayNodes(tree);

    printf("Inorder traversal: ");
    inorder(tree);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(tree);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(tree);
    printf("\n");

    int searchElement = 4;
    printf("Searching for %d: ", searchElement);
    isFound(tree, searchElement);
    printf("\n");

    searchElement = 5;
    printf("Searching for %d: ", searchElement);
    isFound(tree, searchElement);
    printf("\n");

    int deleteElement = 3;
    printf("Deleting %d\n", deleteElement);
    delete(&tree, deleteElement);

    printf("Inorder traversal after deletion: ");
    inorder(tree);
    printf("\n");

    return 0;
}