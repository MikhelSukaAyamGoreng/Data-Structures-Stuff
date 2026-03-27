#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char name;
    struct node *next;
    struct node *prev;
}node;
node *head = NULL;

node *push(node *head, char target){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->name = target;

    node *curr = head;
    if (head == NULL) return newNode;
    else {
        while (curr->next != NULL) curr = curr->next;
    }
    curr->next = newNode;
    return head;
}

int main() {
    char x; scanf("%d", &x);
    for (char i = 0; i < x; i++) {
        char val; scanf("%d", &val);
        head = push(head, val);
    }

    return 0;
}