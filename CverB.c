#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int val;
    struct Node *right;
    struct Node *left;
} Node;

struct Node *newNode(int x) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = x;
    temp->right = temp->left = NULL;
    return temp;
}

struct Node *insert(Node *root, int target) {
    if (root == NULL) root = newNode(target);
    else if (root->val > target) {
        root->left = insert(root->left, target);
    }
    else {
        root->right= insert(root->right, target);
    }
    
    return root;
}

int main() {
    Node *root = NULL;

    int x, y;
    scanf("%d", &x);
    
    int max[x];
    int trueMax = 0;
    for (int i = 0; i < x; i++) {
        scanf("%d", &y);
        
        if (y > trueMax) {
            trueMax = y;
        }
        max[i] = trueMax;
        
        root = insert(root, y);
    }

    for (int i = 0; i < x; i++) {
        printf("%d\n", max[i]);
    }
    return 0;
}







 
