#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *right;
    struct node *left;
}node;

node *newNode(int target) {
    node *Node = (node *)malloc(sizeof(node));
    Node->val = target;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}

node *push(node *root, int target) {
    if (root == NULL) root = newNode(target);
    else if (target > root->val) root->right = push(root->right, target);
    else root->left = push(root->left, target);
    return root;
}

node *find(node *root) {
    node *curr = root;
    curr = curr->left;
    while (curr->right != NULL) curr = curr->right;
    return curr;
}

node *del(node *root, int target) {
    if (root == NULL) return NULL;

    if (target > root->val) root->right = del(root->right, target);
    else if (target < root->val) root->left = del(root->left, target);
    else {
        if (root->right == NULL || root->left == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            node *temp = root->left;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) {
            node *temp = root->right;
            root = root->left;
            free(temp);
        }
        else {
            node *prodecessor = find(root);
            root->val = prodecessor->val;
            root->left = del(root->left, prodecessor->val);
        }
    }
    return root;
}

int main() {
    node *root = NULL;

    int x; scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        int val; scanf("%d", &val);
        root = push(root, val);
    }
}