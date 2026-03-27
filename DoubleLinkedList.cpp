#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
    struct node *prev;
}node;

node *newNode(int target){
    node *Node = (node*)malloc(sizeof(node));
    Node->val = target;
    Node->next = NULL; 
    Node->prev = NULL;
    return Node;
}

node *push(node *head, int target) {
    node *curr = head;
    if (head == NULL) return newNode(target);
    else {
        while (curr->next != NULL) {
            curr = curr->next;
        }
    }
    curr->next = newNode(target);
    curr->next->prev = curr;
    return head;
}

node *del(node *head, int target) {
    node *curr = head;
    if (head == NULL) return NULL;
    if (head->val == target) {
        node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        return head;
    }
    else {
        while (curr->next != NULL && curr->next->val != target) {
            curr = curr->next;
        }
        if (curr->next == NULL) return head;
        else {
            node *temp = curr->next;
            curr->next = temp->next;
            if (temp->next != NULL) temp->next->prev = curr;
            free(temp);
            return head;
        }
    }
}

void view(node *head, int rep) {
    node *curr = head;
    for (int i = 0; i < rep; i++) {
        printf("%d", curr->val);
        curr = curr->next;
    }
}

int main() {
    node *head = NULL;

    int x;scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        int val; scanf("%d", &val);
        head = push(head, val);
    }

    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        int target; scanf("%d", &target);
        head = del(head, target);
    }

    scanf("%d ", &x);
    view(head, x);
    return 0;
}