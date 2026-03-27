#include<stdio.h>
#include<string.h>

typedef struct student {
    int score;
    char name[1000];
    struct student *next;
    struct student *previous;
}student;

student std;

// The Efficient Way
struct student *reverse(struct Node *head) {
    struct student *prev = NULL;
    struct student *after = NULL;
    struct student *current = head;

    while (current != NULL) {
        after = current->next;
        current->next = prev;
        prev = current;
        current = after;
    }

    return prev;
}

// Insertion #middle
struct student *insertionMid (struct student **headRef, int val, char nem[]) {
    struct student *NewNode = (struct student *)malloc(sizeof(struct student));
    NewNode->score = val;
    strcpy(NewNode->name, nem);
    
    NewNode->next = (*headRef);
    (*headRef) = NewNode;
}

// Insertion #End
struct student *insertion (struct student *head, int val, char nem[]) {
    struct student *NewNode = (struct student *)malloc(sizeof(struct student)); 
    NewNode->score = val;
    strcpy(NewNode->name, nem);
    NewNode->next = NULL;
    
    
    struct student *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = NewNode;
    return NewNode;
}

// Deletion
struct student *deletion (struct student *head, char nem[]) {
    if (head != NULL && strcmp(head->name, nem) == 0) {
        struct student *temp = head;
        head->next = head;
        free(temp);
        return head;
    }

    struct student *current = head;

    while (current != NULL && current->next != NULL) {
        if (strcmp(nem, current->next->name) == 0) {
            struct student *temp = current->next;
            current->next = current->next->next;
            free(temp);
            return head;
        }   
        current = current->next;
    }

    return head;
}

// Main Menu
int main() {
    int x;
    printf("Choose menu: \n");
    printf("1. Add new to List\n");
    printf("2. Print List\n");
    printf("3. Search List\n");
    printf("4. Remove a list \n");

    printf("Give the number of the menu you want to acces: ");
    scanf("%d", &x);

    if (x == 1) {

    }
    else if (x == 2) {

    }
    else if (x == 3) {

    }
    else {
        printf("Plese choose the available menu \n");
    }

    return 0;
}