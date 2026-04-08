#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int current;
    int next;
    struct node *next;
}node;

int main() {
    int place, road;
    scanf("%d %d", &place, &road);

    int a[road], b[road];
    for (int i = 0; i < road; i++) {
        scanf("%d %d", a[i], b[i]);
    }

    return 0;
}