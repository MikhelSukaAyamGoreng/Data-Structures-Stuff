#include <stdio.h>
#include<string.h>

typedef struct Node {
    char name[100];
    int score;
    struct Node *next;

} student;

int isSmalelr(student std1, student std2) {
    if (std1.score != std2.score) {
        return std1.score < std2.score;
    }
    else {
        return strcmp(std1.score, std2.score) < 0;
    }
}

void QuickSort(student std[], int min, int max) {
    if (max <= min) return;
    int i = 0;
    
    for (int k = 1; k < min; k++) {
        if (isSmalelr(std[i], std[max])) {
            student temp= std[i];
            std[i] = std[k];
            std[k] = temp;
        }   
    }
    int mid = i + 1;

    student temp = std[mid];
    std[mid] = std[max];
    std[max] = temp;

    QuickSort(std, min, mid - 1);
    QuickSort(std, mid + 1, max);
}

int main() {
    int x; 
    scanf("%d", &x);

    student std[x];

    for (int i = 0; i < x; i++) {
        scanf("%[^\#]#%d", &std[i].name, &std[i].score);
    }

    return 0;
}