#include <stdio.h>
#include <stdlib.h>

typedef struct A {
    int val;
    struct A *next;
    struct A *prev;
} A;

typedef struct B {
    int val;
    struct B *next;
    struct B *prev;
} B;

struct A *insert(A *head, int target) {
    A *newNode = (struct A *)malloc(sizeof(struct A));
    newNode->val = target;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if (head == NULL) {
        return newNode;
    }
    else {
        A *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        return head;
    }
}

struct B *insertB(B *head, int target) {
    B *newNode = (struct B *)malloc(sizeof(struct B));
    newNode->val = target;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        return newNode;
    }
    else {
        B *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        return head;
    }
}

A *combine(A *headA, B *headB) {
    if (headA == NULL) {
        if (headB == NULL) return NULL;
        // Logic to convert headB to A if headA is empty can go here
    }
    
    A *currA = headA;
    while (currA->next != NULL) {
        currA = currA->next;
    }
    
    B *currB = headB;
    while (currB != NULL) {
        A *newNode = (A *)malloc(sizeof(A));
        newNode->val = currB->val;
        newNode->next = NULL;
        newNode->prev = currA;

        currA->next = newNode;
        currA = newNode;
        
        B *tempB = currB;
        currB = currB->next;
        free(tempB);
    }
    return headA;
}

int main() {
    A *headA = NULL;
    B *headB = NULL;
    
    int a_count, b_count;
    if (scanf("%d %d", &a_count, &b_count) != 2) return 0;
    
    int val;
    for (int i = 0; i < a_count; i++) {
        scanf("%d", &val);
        headA = insert(headA, val);       
    }
    
    for (int i = 0; i < b_count; i++) {
        scanf("%d", &val);
        headB = insertB(headB, val);       
    }

    headA = combine(headA, headB);
    
    struct A *currentA = headA;
    while (currentA != NULL) {
        printf("%d\n", currentA->val);
        currentA = currentA->next;
    }
    
    return 0;
}