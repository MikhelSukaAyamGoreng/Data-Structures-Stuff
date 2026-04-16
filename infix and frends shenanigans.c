#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *right;
    struct node *left;
}node;

node *root = NULL;

node *create(int target_val){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->val = target_val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(node **root, int target_val){
    node *newNode = create(target_val);
    if (*root == NULL) {*root = newNode; return;}
    else if ((*root)->val > target_val) {insert(&(*root)->left, target_val);}
    else if ((*root)->val < target_val) {insert(&(*root)->right, target_val);} 
}

void del(node **root, int target_val) {
    if (*root == NULL) return;
    node *temp = *root;
    if ((*root)->val > target_val) {del(&(*root)->left, target_val);}
    else if ((*root)->val < target_val) {del(&(*root)->right, target_val);}
    else {
        if ((*root)->left == NULL) {
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
            del(&(*root)->right, target_val);
        }
    }
}

//intfix
void infinix(node **root) {
    if (*root == NULL) return;
    if ((*root)->left != NULL) {infinix(&(*root)->left);}
    printf("%d", (*root)->val);
    if ((*root)->right != NULL) {infinix(&(*root)->right);}
}

//prefix 
void prefix(node **root) {
    if (*root == NULL) return;
    printf("%d", (*root)->val);
    if ((*root)->left != NULL) { prefix(&(*root)->left); }
    else if ((*root)->right != NULL) { prefix(&(*root)->right); }
}

//postfix
void postfix(node **root) {
    if (*root == NULL) return;
    if ((*root)->left != NULL) { prefix(&(*root)->left); }
    else if ((*root)->right != NULL) { prefix(&(*root)->right); }
    printf("%d", (*root)->val);
}

int main() {
    int x; scanf("%d", &x);
    for (int i = 0; i <x ;i++) {
        int target; scanf("%d", &target);
        insert(&root, target);
    }
}