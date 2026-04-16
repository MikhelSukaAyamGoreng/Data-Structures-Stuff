#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
}node;

node *root = NULL;

node *create(int target) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->val = target;
    return newNode;
}

void insert(node **root, int target) {
    node *newNode = create(target);
    if (*root == NULL) *root = newNode;
    else if ((*root)->val > target) { insert(&(*root)->left, target); }
    else if ((*root)->val < target) { insert(&(*root)->right, target); }
}

void del(node **root, int target) {
    if (*root == NULL)return;
    node *temp = *root;
    if ((*root)->val < target) {
        del(&(*root)->right, target);
    }
    else if ((*root)->val > target) {
        del(&(*root)->left, target);
    }
    else {
        if((*root)->left == NULL && (*root)->right == NULL) {
            free(temp);
            return;
        }
        else if((*root)->left == NULL) {
            *root = (*root)->right;
            free(temp);
            return;
        }
        else if((*root)->right = NULL) {
            *root = (*root)->left;
            free(temp);
            return;
        }
        else {
            temp = (*root)->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            (*root)->val = temp->val;
            del(&(*root)->right, temp->val);
        }
    }
}