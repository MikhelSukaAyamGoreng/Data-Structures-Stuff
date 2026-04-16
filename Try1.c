#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    node *next;
}node;

typedef struct queu {
    node *front;
    node *rear;
} queu;

node *create(int target){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->val = target;
    newNode->next = NULL;
    return newNode;
}

void insert(queu *qt, int target) {
    node *newNode = create(target);
    if (qt->front == NULL) {
        qt->front = qt->rear = newNode;
        return;
    }
    else {
        qt->rear = newNode;
        return;
    }
}

void del(queu *qt, int target) {
    if (qt == NULL) return;
    else {
        node *temp = qt->front;
        int target_val = temp->val;
        qt->front = qt->front->next;
        qt->front->val = target_val;
        free(temp);
        return;
    }
}

void insert(node **head, int target) {
    node *newNode = create(target);
    newNode->next = *head;
    *head = newNode;
    return;
}

void del (node **head, int target) {
    if (*head == NULL) return;
    else {
        node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
}