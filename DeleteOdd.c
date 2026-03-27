#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node;

struct node *insert(node *head, int enter) {
    node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->val = enter;
    newNode->next = NULL;
    node *temp = head;

    if (head == NULL) {
        return newNode;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
    }

    temp->next = newNode;
    return head;
}

struct node *even(node *head) {
    node *current = head;
    
    while (head != NULL && head->next != NULL && head->val % 2 != 0) {
        node* temp = head;
        head = head->next;
        free(temp);
    }

    while (current != NULL && current->next != NULL) {
        if (current->next->val % 2 != 0) {
            node *temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else current = current->next;
    }

    return head;
}

int main() {
    node *head = NULL;

    int x;
    scanf("%d", &x);
    
    int arr[x];
    for (int i = 0; i < x; i++) {
        scanf("%d", &arr[i]);
        head = insert(head, arr[i]);
    }

    head = even(head);
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    return 0;
}