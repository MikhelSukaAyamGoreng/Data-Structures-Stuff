#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
}node;

node *root = NULL;

node *create(int target_val) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->val = target_val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(node **root, int target_val) {
    node *newNode = create(target_val);
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    else if ((*root)->val < target_val) {
        insert(&(*root)->right, target_val);
    }
    else if ((*root)->val > target_val) {
        insert(&(*root)->left, target_val);
    }
}

void del(node **root, int target) {
    if (*root == NULL) return;

    if ((*root)->val > target) {
        del(&(*root)->left, target);
    }
    if ((*root)->val < target) {
        del(&(*root)->right, target);
    }
    else {
        node *temp = *root;
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(temp);
            return;
        }
        else if ((*root)->left == NULL) {
            *root = (*root)->right;
            free(temp);
            return;
        }
        else if ((*root)->right == NULL) {
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

int search(node **root, int target, int total) {
    if (*root == NULL) return -1;
    else if ((*root)->val == target) {
        return total + 1;
    }
    else if ((*root)->val > target) {
        search(&(*root)->left, target, total);
    }
    else if ((*root)->val < target) {
        search(&(*root)->right, target, total);
    }
}

int main() {
    int x; scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        int target; scanf("%d", &target);
        insert(&root, target);
    }

    printf("How much do you want to delete?");
    scanf("%d", &x);
    printf("Enter their values: \n");
    for (int i = 0; i < x; i++) {
        int target; scanf("%d", &target);
        del(&root, target);
    }

    printf("Insert the value you wanted to searh: \n");
    scanf("%d", &x);
    int total = 0;
    total = search(&root, x, total);
    printf("Your value is found in %d tries", total);
    return 0;
}