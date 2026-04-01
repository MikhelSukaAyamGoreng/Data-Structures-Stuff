#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_string 100
#define max_table 100

typedef struct node {
    char name[max_string];
    node *next;
}node;

node *hash_table[max_table];

int hash(char *name) {
    int len = strlen(name);
    int hash_val = 0;
    for (int i = 0; i < len; i++) {
        hash_val += name[i];
    }
    return hash_val % max_string;
}

void initialize () {
    for (int i = 0; i < max_table; i++) {
        hash_table[i] = NULL;
    }
}

void print() {
    for (int i = 0; i < max_table; i++) {
        if (hash_table[i] == NULL) {
            printf("%d", i);
        }
        else {
            printf("%d", hash_table[i]->name);
        }
    }
}

bool hash_insert (node *p) {
    if (p == NULL) return false;
    int index = hash(p->name);
    if (hash_table[index] == NULL) {
        hash_table[index] = p;
    }
}

node *search(char *name) {
    int index = hash(name);
    if (hash_table[index] != NULL &&
        strcmp(hash_table[index]->name, name) == 0) {
            return hash_table[index];
    }
}

node *newNode(node *head, char target_name[]) {
    node *Node = (node*)malloc(sizeof(node));
    strcpy(Node->name, target_name);
    Node->next = NULL:
    return Node;
}

int main() {
    intialize();

    int x; scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        char name[max_string]; scanf("%[^/n]", name);
        
    }
}