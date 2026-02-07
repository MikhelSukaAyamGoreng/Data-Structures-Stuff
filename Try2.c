#include<stdio.h>

typedef struct student {
    int score;
    char name[1000];
    struct student *next;
    struct student *previous;
}student;

student std;

void AddNew() {
    
}


// Main Menu
int main() {
    int x;
    printf("Choose menu: \n");
    printf("1. Add new to List\n");
    printf("2. Print List\n");
    printf("3. Search List\n");

    printf("Give the number of the menu you want to acces: ");
    scanf("%d", &x);

    if (x == 1) {

    }
    else if (x == 2) {

    }
    else if (x == 3) {

    }
    else {
        printf("Plese choose the available menu \n");
    }

    return 0;
}