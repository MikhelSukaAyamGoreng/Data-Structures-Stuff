#include <stdio.h>
#include <stdlib.h>

#define max 100

typedef struct node{
    int key;
    int val;
    struct node *next;
}node;

typedef struct hashtable{
    node **table;
}hashtable;

hashtable *initialize() {
    hashtable *ht = (hashtable*)malloc(sizeof(hashtable));
    ht->table = (node**)malloc(sizeof(node*) * max);
    for (int i = 0; i < max; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

node *create(int target, int target_hash) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->val = target;
    newNode->key = target_hash;
    newNode->next = NULL;
    return newNode;
}

unsigned int hash(int target) {
    return target % max;
}

void insert(hashtable *ht, int target) {
    unsigned int target_key = hash(target);

    node *entry = ht->table[target_key];
    node *prev = NULL;
    
    while (entry != NULL) {
        if (entry->val == target) {
            return;
        }
        
        prev = entry;
        entry = entry->next;
    }
    
    node *newNode = create(target, target_key);
    if (prev == NULL) ht->table[target_key] = newNode;
    else {
        prev->next = newNode;
    }
}

int find(hashtable *ht, int target) {
    unsigned int target_key = hash(target);

    node *entry = ht->table[target_key];
    
    while (entry != NULL) { 
        if (entry->key == target_key) {
            return entry->val;
        }
        entry = entry->next;    
    }
}

int main() {

}