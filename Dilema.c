#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
}node;

node *push(node *head, int target) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->val = target;
    newNode->next = NULL;

    node *curr = head;
    if (head == NULL) return newNode;
    else {
        while (curr->next != NULL) {
            curr = curr->next;
        }
    }
    curr->next = newNode;
}

int pop(node **head) {
    node *temp = *head;
    int value = (*head)->val;
    *head = (*head)->next;
    free(temp);
    return value;
}

int main() {
    node *head = NULL;

    int x; scanf("%d", &x); int arr[x];
    for (int i = 0; i < x; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < x; i++) {
        head = push(head, arr[i]);
    }

    int projects[x];
    for (int i = 0; i < x; i++) {
        scanf("%d", &projects[i]);
    }

    node *curr = head; int found = 0; int total = x;
    while (curr != NULL && found < total) {
        
        if (projects[found] != curr->val) {
            int value = pop(&curr);
            head = push(head, value);
        }
        
        else if (projects[found] == curr->val) {
            curr = curr->next;
            found++;
            total--;
        }
    }

    printf("%d", total - found);
    return 0;
}