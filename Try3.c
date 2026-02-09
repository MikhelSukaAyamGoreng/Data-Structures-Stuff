#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[1000];
    int age;
    struct node *next;
} node;


// If we want to modify the struct itself we must call 
// the struct itself. We CANNOT use a function then call
// the structure
node *add (node *top, int value, char name[]) {
    node *NewNode = (node *)malloc(sizeof(node));

    strcpy(NewNode->name, name);
    NewNode->age = value;

    NewNode->next = top;
    return NewNode;
}

int search (node *head, int target) {
    node *current = head;
    
    int i = -1;
    while (current != NULL) {
        if (current->age == target) {
            return i++;
        }
        else {
            current = current->next;
            i++;
        }
    }
}

int main() {    
    node *stack = NULL;
    
    int x;
    char name[1000];
    scanf("%d %[^\n]", &x, name);

    stack = add(stack, x, name);

    int target;
    scanf("%d", &target);

    add(stack, x, name);

    int result = search(stack, target);
    printf("%d", result );
}
