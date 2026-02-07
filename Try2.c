#include<stdio.h>

typedef struct student {
    int score;
    char name[1000];
    struct student *next;
    struct student *previous;
}student;


student *addNew(int score, char name[]) {
    student *new = malloc (10 * sizeof(int) + 100 * sizeof(char));
}

int main() {
    student head, tail;
    
    head.score = NULL;
    tail.score = NULL;

    int x;
    scanf("%d", &x);

    for (int i = 0; i < x; i++) {
        scanf("%d", )
    }
    
    return 0;
}