#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[100];
    struct node *next;
}node;

void push(node **head, char *word){
    node *newNode = (node *)malloc(sizeof(node));
    strcpy(newNode->name, word);
    newNode->next = NULL;

    node *curr = *head;
    if (*head == NULL) *head = newNode;
    else {
        while (curr->next != NULL) {
            curr = curr->next;
        }
    }
    curr->next = newNode;
}

void viewAll(node *head, char *word){
    node *curr = head;
    while (curr != NULL) {
        printf("%s\n", curr->name);
        
        curr = curr->next;
    }
}

int main() {
    printf("--------------------------------------------------\n");
    printf("Boogle Menu: \n");
    printf("1. Release new slang words\n");
    printf("2. Search slang word\n");
    printf("3. View all slang words with a certain prefix word\n");
    printf("4. View all slang words\n");
    printf("5. Exit\n");
    printf("--------------------------------------------------\n");
    
    printf("Choose (1-5): "); int choose; scanf("%d", &choose);
    if (choose == 1) {
        
    }
    else if (choose == 2) {
        search();
    }
    else if (choose == 3) {
        viewPrefix();
    }
    else if (choose == 4) {
        viewAll();
    }
    else if (choose == 5) {
        printf("Thank you.. Have a nice day :)\n");
        return 0;
    }    
}