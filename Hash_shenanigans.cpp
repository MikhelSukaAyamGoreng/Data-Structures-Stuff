#include <stdio.h>
#include <stdlib.h>

#define max 100

typedef struct node {
    int key;
    int val;
    struct node *next;
}node;

typedef struct hash_table {
    node **table;
}hash_table;

hash_table *initialize() {
    hash_table *newTable = (hash_table*)malloc(sizeof(hash_table));
    newTable->table = (node**)malloc(sizeof(node *) * max);
    for (int i = 0; i < max; i++) {
        newTable->table[i] = NULL;
    }
    return newTable;
}

unsigned int hash(int target_val) {
    return target_val % max;
}

node *create(int target_val, int target_key) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->key = target_key;
    newNode->val = target_val;
    newNode->next = NULL;
    return newNode;
}

void insert(hash_table *ht, int target_val) {
    unsigned target_key = hash(target_val);

    node *tab = ht->table[target_key];
    
    node *prev;
    while (tab != NULL) {
        if (tab->val == target_val) {
            node *temp = tab;
            tab = prev;
            free(temp);
            return;
        }
        prev = tab;
        tab = tab->next;
    }
   
    node *newNode = create(target_val, target_key);
    if (tab == NULL) {
        ht->table[target_key] = newNode;
        return;
    }
    else {
        prev->next = newNode;
    }
}

int main() {
    hash_table *h_t = initialize();

    int x; scanf("%d", &x);
    for (int i = 0; i < x; i++) {

    }
    return 0;
}