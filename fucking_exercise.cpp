#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

typedef struct node {
    int val;
    struct node *next;
    struct node *prev;
}node;

node *head = NULL;
node *tail = NULL;

node *newNode (int target_val) {
    node *New = (node *)malloc(sizeof(node));
    New->val = target_val;
    New->next = NULL;
    New->prev = NULL;
    return New;
}

void push(node **head, node **tail, int target_val, char operation) {
    node *Node = newNode(target_val);
    if (*head == NULL) {
        *head = Node;
        *tail = Node;
        return;
    }
    else {
        Node->prev = *tail;
        (*tail)->next = Node;
        *tail = Node;
        return;
    }
}

void pop(node **head, node **tail, int target_value) {
    node *curr = *head;
    
    if (*head == NULL) {
        printf("list is empty\n");
        return;
    }
    else if ((*head)->val == target_value) {
        node *temp = *head;
        *head = (*head)->next;
        if (*head == NULL) {
            *tail = NULL;
        }
        else {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    else if ((*tail)->val == target_value) {
        node *temp = *tail;
        *tail = (*tail)->prev;
        free(temp);
        return;
    }
    else {
        while (curr->next->val != target_value && curr->next != NULL) {
            curr = curr->next;
        }
        
        node *temp = curr->next;
        curr->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = curr;
        }
        free(temp);
        return;
    }
}

void reverse_print(node **head, node **tail) {
    node *curr = *tail;
    if (*head == NULL) {
        printf("List is empty\n");
    }
    else {
        while (curr != NULL) {
            printf("%d", curr->val);
            curr = curr->prev;
        }
    }
    return;
}
 
int main() {
    int x; scanf("%d", &x);
    
    for (int i = 0; i < x; i++) {
        fscanf("%d", &x);
    }

    for (int i = 0; i < x; i++) {
        char operation[max]; int k;
        scanf("%s%d", operation, &k);
        if (strcmp(operation, "ENDQUE") == 0) {
            push
        }
    }
}