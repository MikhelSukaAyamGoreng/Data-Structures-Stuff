#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct node {
    char key;
    int freq;
    int occupied;
} node;

node table[MAX];
int order[MAX];
int total = 0;

int hash(char val) {
    return (val - 'a') % MAX;
}

void insert(char target_val) {
    int idx = hash(target_val);
    
    for (int i = 0; i < MAX; i++) {
        int prob = (idx + i) % MAX;
        if (table[prob].occupied == 0) {
            table[prob].key = target_val;
            table[prob].occupied = 1;
            table[prob].freq = 1;
            order[total++] = prob;
            return;
        } else if (table[prob].key == target_val) {
            table[prob].freq++;
            return;
        }
    }
}

int main() {
    char str[1001];
    scanf("%s", str);
    
    for (int i = 0; i < MAX; i++) {
        table[i].occupied = 0;
        table[i].freq = 0;
    }

    int x = 0;
    while (str[x] != '\0') {
        insert(str[x]);
        x++;
    }

    // Pin order[0], stable sort only order[1..total-1] by freq descending
    for (int i = 2; i < total; i++) {
        int tmp = order[i];
        int j = i - 1;
        while (j >= 1 && table[order[j]].freq < table[tmp].freq) {
            order[j + 1] = order[j];
            j--;
        }
        order[j + 1] = tmp;
    }

    for (int i = 0; i < total; i++) {
        printf("%c %d\n", table[order[i]].key, table[order[i]].freq);
    }

    return 0;
}