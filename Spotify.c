#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char name[100];
    int duration;       // FIX 1: changed float to int — duration is in seconds (integer)
    struct node *next;
    struct node *prev;
} node;

node *head = NULL;
node *tail = NULL;

// FIX 2: newNode now also sets duration (was missing in original)
node *newNode(char name[], int duration) {
    node *Node = (node *)malloc(sizeof(node));
    strcpy(Node->name, name);
    Node->duration = duration;  // FIX 3: was missing this line entirely
    Node->next = NULL;
    Node->prev = NULL;
    return Node;
}

// FIX 4: songName parameter changed from char to char[] (string, not single char)
// FIX 5: return type changed from void* to void (we don't use the return value)
void push(node **head, node **tail, char targetName[], char songName[], int songDuration) {
    node *new = newNode(songName, songDuration);

    // FIX 6: check *head == NULL, not head == NULL (head is a pointer-to-pointer)
    if (*head == NULL) {
        *head = new;
        *tail = new;
        return;  // FIX 7: was returning head (wrong type); just return
    }
    // Case: insert at the very beginning — target is "-"
    else if (strcmp(targetName, "-") == 0) {
        new->next = *head;
        (*head)->prev = new;
        *head = new;
    }
    // FIX 8: insert after head when head's name matches target
    else if (strcmp((*head)->name, targetName) == 0) {
        new->next = (*head)->next;
        new->prev = *head;
        if ((*head)->next != NULL)
            (*head)->next->prev = new;
        (*head)->next = new;
        if (*tail == *head)   // if head was also tail, update tail
            *tail = new;
    }
    else {
        // FIX 9: traverse to find the node whose name matches targetName
        node *curr = *head;
        while (curr->next != NULL && strcmp(curr->name, targetName) != 0) {
            curr = curr->next;
        }
        // If we reached the end without finding target, append to tail
        if (strcmp(curr->name, targetName) != 0) {
            new->prev = *tail;
            (*tail)->next = new;
            *tail = new;
        }
        else {
            // Insert new node after curr
            new->next = curr->next;
            new->prev = curr;
            if (curr->next != NULL)
                curr->next->prev = new;
            curr->next = new;
            if (*tail == curr)  // if curr was tail, update tail
                *tail = new;
        }
    }
}

// FIX 10: return type void* -> void (no return value needed)
// FIX 11: parameter node **head, node **tail (not node *head)
void del(node **head, node **tail, char target[]) {
    // FIX 12: curr must be *head (dereference), not head (which is node**)
    node *curr = *head;

    if (curr == NULL) return;  // FIX 13: guard against empty list

    if (strcmp((*head)->name, target) == 0) {
        node *temp = *head;
        *head = (*head)->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        else
            *tail = NULL;  // list became empty
        free(temp);
        return;
    }

    while (curr->next != NULL && strcmp(curr->next->name, target) != 0) {
        curr = curr->next;
    }

    if (curr->next == NULL) {
        // FIX 14: target not found — do nothing (or optionally delete tail)
        // Based on problem: if not found, do nothing
        return;
    }
    else {
        node *temp = curr->next;
        curr->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = curr;
        else
            *tail = curr;  // FIX 15: update tail if last node was deleted
        free(temp);
        return;
    }
}

// FIX 16: added SkipPlay function — X=1 forward, X=0 backward
void SkipPlay(node **head, node **tail, int mode) {
    if (mode == 1) {
        // Forward traversal
        node *curr = *head;
        while (curr != NULL) {
            int mins = curr->duration / 60;
            int secs = curr->duration % 60;
            // FIX 17: output format is <name> - <mm>:<ss>
            printf("%s - %d:%02d\n", curr->name, mins, secs);
            curr = curr->next;
        }
    } else {
        // Backward traversal
        node *curr = *tail;
        while (curr != NULL) {
            int mins = curr->duration / 60;
            int secs = curr->duration % 60;
            printf("%s - %d:%02d\n", curr->name, mins, secs);
            curr = curr->prev;
        }
    }
}

int main() {
    int x;
    scanf("%d", &x);  // number of songs to add

    for (int i = 0; i < x; i++) {
        char target[100];
        char name[100];
        int duration;
        // FIX 18: format string uses \n (newline), not /n — and reads strings properly
        scanf(" %[^#]#%[^#]#%d", target, name, &duration);
        push(&head, &tail, target, name, duration);
    }

    scanf("%d", &x);  // number of songs to delete
    for (int i = 0; i < x; i++) {
        char target[100];
        // FIX 19: was scanf("%d", &target) — should be %s or %[^\n] for a string
        scanf(" %[^\n]", target);
        del(&head, &tail, target);
    }

    int mode;
    // FIX 20: was scanf("%d", x) — missing & operator; also wrong variable name
    scanf("%d", &mode);

    // FIX 21: SkipPlay now takes mode parameter; was called incorrectly
    SkipPlay(&head, &tail, mode);

    return 0;
}