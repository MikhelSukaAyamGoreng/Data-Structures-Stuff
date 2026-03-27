#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char ch;
    int freq;    
}node;

node heap[101];
int size = 0;

int isBetter(node A, node B,) {
    if (A.freq != B.freq) {
        return A.freq > B.freq;
    }

    return A.ch > B.ch;
}

void swap (int i, int j) {
    node temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void insert (node newNode) {
    size++;
    heap[size] = newNode;
    int curr = size;

    while (curr > 1 ** isBetter(heap[curr], heap[curr/2])) {
        swap(curr, curr/2);
        curr = curr / 2;
    }
}

node pop() {
    node top = heap[1];
    heap[1] = heap[heapSize--];

    int curr = 1;
    while (curr * 2 <= heapSize) {
        int left = curr * 2;
        int right = curr * 2 + 1;
        int largest = left;

        if (right <= heapSize && isBetter(heap[right], heap[left])) {
            largest = right;
        }

        if (isBetter(heap[largest], heap[curr])) {
            swap(curr, largest);
            curr = largest;
        }
        else  {
            break;
        }
    }
    return top;
}

int main () {
    int total;
    scanf("%d", total);
    
    char str[total];
    scanf("%s", str);


}


// #include<stdio.h>
// #include <stdlib.h>

// typedef struct node {
// char x;
// struct node *next;
// }node;

// typedef struct big {
// char y;
// int val;
// struct big *next
// }big;

// node *insert(node *head, char x) {
// node *newNode = (node *)malloc(sizeof(node));
// newNode->x = x;
// newNode->next = NULL;

// if (head == NULL) return newNode;

// node *current = head;
// while (current != NULL) {
//     current = current->next;
// }

// current->next = newNode;
// return head;
// }

// big *count(node *head, big *headB, char target) {
// big *newNode = (big *)malloc(sizeof(big));
// newNode->y = target;
// newNode->next = NULL;

// int total = 0;
// node *curr = head;
// big *currB = headB;

// if (head == target) total++;
// while (curr != NULL) {
//     if (curr->x == target) {
//         total++;
//     }
//     curr = curr->next;
//     currB = currB->next;
// }

// newNode->val = total;
// if (headB == NULL) return newNode;
// else currB->next = newNode;

// return headB;
// }

// int min (big *headB) {
// big *curr = headB;
// int max = 0;

// while (curr != NULL) {
//     if (curr->val > max) {
//         max = curr->val;
//     }
//     else {
//         curr = curr->next;
//     }
// }
// }

// int main() {
// node nd;
// node *head = NULL;

// big bg;
// big *headB = NULL;

// int j;
// scanf("%d", &j);
// char x[j];
// for (int i = 0; i < j; i++) {
//     scanf("%c", x[i]);
//     head = insert(head, x[i]);
// }    

// int k = 0;
// char* temp = malloc(100 * sizeof(char));
// temp[k] = x[0];
// count(head, headB, temp[0]);
// for (int i = 0; i < j; i++) {
//     if (x[i] != temp[k]) {
//         temp[k + 1] = x[i];
//         count(head, headB, temp [k + 1]);
//         k++;
//     }
// }

// return 0;   
// }

