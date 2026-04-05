#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct node {
    int duration;
    char name[MAX];
    struct node *next;
    struct node *prev;
} node;
node *head = NULL;
node *tail = NULL;

node *newNode(int target_duration, char target_name) {
    node *Node = (node*)malloc(sizeof(node));
    Node->duration = target_duration;
    strcpy(Node->name, target_name);
    Node->next = NULL;
    Node->prev = NULL;
}

void push(node **head, node **tail, int target_duration, char target_name[], char find_name[]) {
    node *New = newNode(target_duration, target_name);
    if (head == NULL) {
        *head = New;
        *tail = *head;
        return;
    }
    else if (strcmp(find_name, 'first') == 0) {
        *head = (*head)->next;
        (*head)->prev = New;
        *head = (*head)->prev;
        return;
    }
    else if (strcmp(find_name, (*head)->name) == 0){
        *head = (*head)->next;
        (*head)->prev = New;
        *head = (*head)->prev;
        if (*head == *tail) *tail = (*tail)->next;        
        return;
    }
    else {
        node *curr = *head;
        while (curr->next != NULL && strcmp(curr->name, find_name) != 0) {
            curr = curr->next;
        }
        if (curr->next != NULL){
            New->prev = curr->prev;
            curr->prev->next = New;
            curr = curr->next;
            curr->prev = New;
            New->next = curr;
            return;
        }
        else {
            New->prev = *tail;
            (*tail)->next = New;
            *tail = (*tail)->next;
            return;
        }
    }
}

void del(node **head, node **tail, char target_name[]) {
    if (strcmp((*head)->name, target_name) == 0) {
        node *temp = *head;
        if (*tail == *head) *tail = (*tail)->next;
        (*head) = (*head)->next;
        free(temp);
    }
    else {
        node *curr = *head;
        while (curr->next != NULL && strcmp(curr->next->name, target_name) != 0) {
            curr = curr->next;
        }
        if (curr->next == *tail) {
           node *temp = *tail;
           *tail = (*tail)->prev; 
            free(temp);
            return;
        }

        node *temp = curr->next;
        curr->next = temp->next;
        curr->next->next->prev = curr;
        free(temp);
        return;
    }
}



int main() {
    int x; scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        int duration; char name[MAX]; char target[MAX];
        scanf("%d#%[^/n]#%[^/n]", &duration, name, target);
        push(&head, &tail, duration, name, target);
    }

    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        char target[MAX]; scanf("%[^/n]", target);
        del(&head, &tail, target);
    }

    int skibidi; scanf("%d", &skibidi);
    
    return 0;
}   