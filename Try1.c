#include <stdio.h>
#include <stdlib.h>

#define max 100

typedef struct node{
    int val;
    int key;
    struct node *next;
}node;

typedef struct hashtable {
    node **table;
}hashtable;

hashtable *initialize() {
    hashtable *newNode = (hashtable*)malloc(sizeof(hashtable));
    newNode->table = (node**)malloc(sizeof(node*) * max);

    for (int i = 0; i < max; i++) {
        newNode->table[i] = NULL;
    }
    return newNode;
}

int hash(int target) {
    return target % max;
}

node *createnode(int target, int target_key) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->val = target;
    newNode->key = target_key;
    newNode->next = NULL;
    return newNode;
}

void hash_table(hashtable *ht, int target_val) {
    unsigned int target_key = hash(target_val);

    node *point = ht->table[target_key];
    node *newNode = createnode(target_val, target_key);
    node *prev = NULL;

    while (point != NULL) {
        if (point->val == target_val) {
            return;
        }
        prev = point;
        point = point->next;
    }

    if (prev == NULL) {
        prev = newNode;
    }
    else {
        prev = point->next;
    }
}

int search(hashtable *ht, int target) {
    unsigned int target_key = hash(target);
    node *point = ht->table[target_key];

    if (point == NULL) {
        return NULL;
    }

    while (point != NULL) {
        if (point == target) {
            return point->key;
        }
        point = point->next;
    }
    return -1;
}

int main() {
    hashtable *ht = initialize();

    int x; scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        int target_val; scanf("%d", &target_val);
        insert(target_val);
    }
}