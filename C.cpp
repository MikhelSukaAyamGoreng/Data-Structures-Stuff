#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

struct Node *NewNode(int value) {
    Node *project = (struct Node *)malloc(sizeof(struct Node));
    project->val = value;
    project->left = project->right = NULL;
    return project;
}

struct Node *insert(Node *root, int test) {
    if (root == NULL) {
        return NewNode(test);
    }
    else if (test > root->val) {
        root->right = insert(root->right, test);
    }
    else  {
        root->left = insert(root->left, test);
    }

    return root;
}

void print(struct Node *root) {
    if (root == NULL) return;
    print(root->left);
    printf("%d\n", root->val);
    print(root->right);
}

int main() {
    Node *root = NULL;
    int x;
    scanf("%d", &x);
    int y[x];
    for (int i = 0; i < x; i++) {
        scanf("%d", &y[i]);
    }

    for (int i = 0; i < x; i++) {
        root = insert(root, y[i]);
    }

    print(root);
}