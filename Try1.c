#include <stdio.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node node_t;

void PrintList(node_t *head) {
    node_t *temporary = head;

    while (temporary != NULL) {
        printf("%d -", temporary->value);
        temporary = temporary->next;
    }
}

node_t *CreateNewNode(int value) {
    node_t *result = malloc(sizeof(node_t));
}

int main() {
    node_t n1, n2, n3;
    node_t *head;

    n1.value = 45;
    n2.value = 8;
    n3.value = 32;

    // This can be reordered
    head = &n1;
    n3.next = &n2;
    n2.next = &n3;
    n1.next = NULL;

    return 0;
}