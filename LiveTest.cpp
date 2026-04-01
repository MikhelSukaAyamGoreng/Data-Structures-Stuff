#include <stdio.h>
#include <stdlib.h>

#define MAX 120;

int main() {
    int arr[MAX];
    for (int i = 0; i < MAX; i++) {
        scanf("%d", arr[i]);
    }
    int k; scanf("%d", &k);
    
    int found = 0;
    for (int i = 0; i < MAX; i++) {
        if (arr[i] == k) {
            found++;
            break;
        }
    }
    
    if (found == 1) printf("Found");
    else printf("Not found");
    return 0;
}