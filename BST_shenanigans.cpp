#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} node;

node *root = NULL;

node *createNew(int target_val) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->val = target_val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert (node **root, int target_val) {
    node *newNode = createNew(target_val);
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    else if ((*root)->val > target_val) {
        insert(&(*root)->left, target_val);
    }
    else if ((*root)->val < target_val) {
        insert(&(*root)->right, target_val);
    }
}


void del (node **root, int target_val) {
    if (*root == NULL) return;

    if ((*root)->val > target_val) {
        del(&(*root)->left, target_val);
    }
    else if ((*root)->val < target_val) {
        del(&(*root)->right, target_val);
    }
    else {
        if((*root)->left == NULL && (*root)->right == NULL) {
            node *temp = *root;
            *root = NULL;
            free(temp);
            return;
        }
        else if ((*root)->left == NULL) {
            node *temp = *root;
            *root = (*root)->right;
            free(temp);
            return;
        }
        else if ((*root)->right == NULL) {
            node *temp = *root;
            *root = (*root)->left;
            free(temp);
            return;
        }
        
        node *temp = (*root)->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        (*root)->val = temp->val;
        del(&(*root)->right, target_val);
        return;
    }
}

int main() {
    int x; scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        int target_val; scanf("%d", &target_val);
        insert(&root, target_val);
    }

    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        int target_val; scanf("%d", &target_val);
        del(&root, target_val);
    }

    return 0;
}