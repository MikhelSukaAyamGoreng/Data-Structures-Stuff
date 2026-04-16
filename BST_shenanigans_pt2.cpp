#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
}node;

node *root = NULL;

node *createNew(int target_val) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->val = target_val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void *insert(node **root, int target_val) {
    node *newNode = createNew(target_val);
    if (*root == NULL) {
        *root = newNode;
    }
    else if ((*root)->val > target_val) {
        insert((&(*root)->left), target_val);
    }
    else if ((*root)->val < target_val) {
        insert((&(*root)->right), target_val);
    }
}

void *del(node **root, int t)