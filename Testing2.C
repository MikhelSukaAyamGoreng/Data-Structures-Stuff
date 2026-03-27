#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char name[100];
    int duration;
    struct node *next;
    struct node *prev;
}node;
node *head = NULL;
node *tail = NULL;

node *newNode(char Tname[], int Tduration) {
    node *new = (node *)malloc(sizeof(node));
    strcpy(new->name, Tname);
    new->duration = Tduration;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void push(node **head, node **tail, char targetName[], char name, int duration) {
    node *new = newNode(name, duration);
    if (*head == NULL) {
        *head = new;
        *tail = new;
        return;
    }
    else if (strcmp(targetName, '-') == 0) {
        new->next = *head;
        (*head)->prev = *head;
        *head = new;
    }
    else if (strcmp((*head)->name, targetName) == 0) {
        new->next = *head;
        (*head)->prev = new;
        *head = new;
        if (*tail == *head) *tail = head;
        return;
    }
    else {
        node *curr = *head;
        while (curr->next != NULL && strcmp(curr->name, targetName) != 0) {
            curr = curr->next;
        }
        if (curr->next != NULL) {
            new->prev = curr->prev;
            new->next = curr;
            curr = curr->next;
            curr->prev = new;
        }
        else if (curr == *tail) {
            new->next = *tail;
            new->prev = (*tail)->prev;
            *tail = (*tail)->next;
            (*tail)->prev = new;
        }
    }
}

void del(node **head, node **tail, char target[100]) {
    if (strcmp((*head)->name, target) == 0) {
        node *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
        return;
    }
    else {
        node *curr = *head;
        while (curr->next != NULL && strcmp(curr->name, target) == 0) curr = curr->next;
        if (*tail == curr) {
            node *temp = curr;
            *tail = (*tail)->prev;
            (*tail)->next = NULL;
            free(temp);
        }
        else {
            node *temp = curr;
            curr = curr->next;
            curr->prev = temp->prev;
            free(curr);
        }
    }
    return;
}

void NP(node **head, node **tail, int target) {
    if (target == 1) {
        (*tail)->next = *head;
        *tail = (*tail)->next;
        *head = (*head)->next;
        (*head)->prev = NULL;
    }
    else if (target == 0) {

    }
    else {
        return;
    }
}

int main() {
    int x; scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        char targetName[100]; char name[100]; int duration;
        scanf("%[^/n]#%[^/n]#%d", targetName, name, duration);
    }

    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        char name[100];
        del(&head, &tail, name);
    }

    node *curr = head;
    while (curr != NULL) {
        printf("%s - %d", curr->name, curr->duration);
        curr = curr->next;
    }
    
    scanf("%d", &x);
    NP(&head, &tail, x);
    return 0;
}