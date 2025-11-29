#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} *BST; 

// an instance of BST creates is a ptr to struct node
void insert(BST* root, int data) {
    if (*root == NULL) {
        BST temp = (BST)malloc(sizeof(struct node));
        if (temp != NULL) {
            temp->data = data;
            temp->left = temp->right = NULL;
            *root = temp;
        }
        return;
    }

    if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else if (data > (*root)->data) {
        insert(&(*root)->right, data);
    }
}

bool search(BST root, int data) {
    if (root == NULL) {
        return false;
    }
    if (data < root->data) {
        return search(root->left, data);
    } else if (data > root->data) {
        return search(root->right, data);
    } else {
        return true;
    }
}