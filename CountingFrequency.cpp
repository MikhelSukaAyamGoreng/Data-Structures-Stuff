#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct node {
    char key;
    int freq;
    int occupied;
}node;

node table[MAX];

int hash(char val) {
    return val % MAX;
}

void insert (char) {

}

int main() {

    return 0;
}