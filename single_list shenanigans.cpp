#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}node;

node *head = NULL;
node *tail = NULL;

node *create(int target) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->val = target;
    newNode->next = NULL;
    return newNode;
}

// stack
void insert (node **head, int target) {
    node *newNode = create(target);
    newNode->next = *head;
    *head = newNode;
}

void del(node **head, int target) {
    if (*head == NULL) {
        return;
    }
    else {
        node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
}

// Queu
typedef struct queue{
    node *front = NULL;
    node *rear = NULL;
}queue;

void insert(queue *qt, int target) {
    node *newNode = create(target);
    if ((qt)->front == NULL) {
        qt->front = qt->rear = newNode;
    }
    else {
        qt->rear->next = newNode;
        qt->rear = newNode;
    }
}

void del(int target, queue *qt) {
    if (qt == NULL) return;
    else {
        node *temp = qt->front;
        int tv = temp->val;
        qt->front = qt->front->next; 
        qt->front->val = tv;
        if (qt->front == NULL) qt->rear = NULL;
        free(temp);
        return;
    }        
}