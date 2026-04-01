#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int val;
    char name[1000];
    struct node *next;
    struct node *prev;
} node;
node *head = NULL;
node *tail = NULL;

node *newNode(int targetVal, char targetName[]) {
    node *Node = (node *)malloc(sizeof(node));
    strcpy(Node->name, targetName);
    Node->val = targetVal;
    Node->next = NULL;
    Node->prev = NULL;
}

int compare(int targetVal, char targetName[], node *target_comp) {
    if (targetVal != target_comp->val) {
        return targetVal > target_comp->val;
    }
    else {
        return strcmp(target_comp->name, targetName);
    }
}

void push(node **head, node **tail, int targetVal, char targetName[]) {
    node *New = newNode(targetVal, targetName);
    if (*head == NULL) {
        *head = New;
        *tail = *head;
        return;
    }
    else if ((*head)->val < targetVal) {
        *head = (*head)->next;
        (*head)->prev = New;
        New->next = *head;
        *head = New;
        return;    
    }
    else {
        node *curr = *head;
        while (curr->next != NULL && strcmp(curr->name, targetName)) {
            curr = curr->next;
        }
        if (compare(targetVal, targetName, curr->next)) {
            node *temp = curr;
            curr = curr->next;
            New->next = curr;
            curr->prev = New;
            if (curr->next == NULL) {
                *tail = New;
            }
            return;
        }
    }
    return;
}

void del(char targetName[], node **head, node **tail) {
    node *curr = *head;
    if (strcmp(curr->name, targetName) == 0) {
        node *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
    else {
        while (curr->next != NULL && strcmp(curr->name, targetName) != 0) {
            curr = curr->next;
        }
        
        
            curr = curr->prev;
            *tail = curr;
        
    }
}

int main() {
    int x;
    scanf("%d", &x);

    for (int i = 0; i < x; i++) {
        int score; char name[1000];
        scanf("%d %[^/n]", &score, name);
        push(&head, &tail, score, name);
    }

    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        char target[100];
        del(target, &head, &tail);
    }

    node *curr = *head;
    while (curr != NULL) {
        printf("%s %d", curr->name, curr->val);
        curr = curr->next;
    }
    return 0;
}
