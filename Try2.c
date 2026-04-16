#include <stdio.h>
#include <stdlib.h>

#define max 100

typedef struct node {
    int val;
    int key;
    struct node *next;
}node;

typedef struct hash_table {
    node **table;
}hash_table;

// Hashing functions
int hash(int target_val){
    return target_val % max;
}

hash_table *initializez() {
    hash_table *newNode = (hash_table*)malloc(sizeof(hash_table));
    newNode->table = (node**)malloc(sizeof(node*) * max);
    for (int i = 0; i < max; i++) {
        newNode->table[i] = NULL;
    }
    return newNode;
}

node *createNode(int target_val, int target_key) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->val = target_val;
    newNode->key = target_key;
    newNode->next = NULL;
    return newNode;
}

void insert(hash_table *ht, int target_val) {
    unsigned int target_key = hash(target_val);

    node *entry = ht->table[target_key];
    node *prev = NULL; 

    while (entry != NULL) {
        if (entry->val == target_val) {
            
            return;
        }
        prev = entry;
        entry = entry->next;
    }
    
    node *newNode = createNode(target_val, target_key);
    if (prev == NULL) {
        ht->table[target_key] = newNode;
        return;
    }
    else {
        prev->next = newNode;
    }
}

int hash_get(hash_table *ht, int target_val) {
    unsigned int target_key = hash(target_val);
    node *entry = ht->table[target_key];
    if (entry == NULL) {
        return -1;
    }

    while (entry != NULL) {
        if (entry->val == target_val) {
            return entry->key;
        }
        entry = entry->next;
    }
    return -1;
}

int main() {
    return 0;
}