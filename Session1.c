#include<stdio.h>

typedef struct Node {
    int val;
    struct Node *prev;
    struct Node *next;
} Node;

struct Node Add(struct Node *head, int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    
    if (head != NULL) {
        head = current;
    
    }
    else {
        head = head->next;
        
    }    
}


int main() {
    struct Node node;
    int x;
    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        int add = scanf("%d", &add);
        Add(node, add);
    }
}