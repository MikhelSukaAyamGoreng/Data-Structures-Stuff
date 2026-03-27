#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

struct Node *newNode(int x) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->val = x;
    node->left = node->right = NULL;
    return node;
}

struct Node *insertion(Node *root, int target) {
    if (root == NULL) {
        root = newNode(target);
    }
    else if (target > root->val) {
        root = insertion(root->right, target);
    }
    else {
        root = insertion(root->left, target);
    }
}

void display(Node *root) {
    if (root == NULL) return;
    else {
        printf("%d", root->val);
        display(root->left);
        display(root->right);
    }
}

int main() {
    Node *root = NULL;
    int x, y;
    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        scanf("%d", &y);
        root = insertion(root, y); 
    }

    display(root);
    return 0;
}