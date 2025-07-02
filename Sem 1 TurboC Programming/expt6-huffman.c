#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char ch;
    int freq;
    struct node *left;
    struct node *right;
} Node;

Node *heap[100];
int heapSize = 0;

void Insert(Node *element) {
    int now;
    heapSize++;
    heap[heapSize] = element;
    now = heapSize;
    while (heap[now / 2]->freq > element->freq) {
        heap[now] = heap[now / 2];
        now /= 2;
    }
    heap[now] = element;
}

Node *DeleteMin() {
    Node *minElement, *lastElement;
    int child, now;
    minElement = heap[1];
    lastElement = heap[heapSize--];
    for (now = 1; now * 2 <= heapSize; now = child) {
        child = now * 2;
        if (child != heapSize && heap[child + 1]->freq < heap[child]->freq) {
            child++;
        }
        if (lastElement->freq > heap[child]->freq) {
            heap[now] = heap[child];
        } else {
            break;
        }
    }
    heap[now] = lastElement;
    return minElement;
}

void print(Node *temp, char *code) {
    char leftcode[10], rightcode[10];
    int length;
    if (temp->left == NULL && temp->right == NULL) {
        printf("char %c code %s\n", temp->ch, code);
        return;
    }
    strcpy(leftcode, code);
    strcpy(rightcode, code);
    length = strlen(code);
    leftcode[length] = '0';
    leftcode[length + 1] = '\0';
    rightcode[length] = '1';
    rightcode[length + 1] = '\0';
    print(temp->left, leftcode);
    print(temp->right, rightcode);
}

int main() {
    int n, freq, i;
    char ch;
    Node *temp, *tree;
    char code[10];
    heap[0] = (Node *)malloc(sizeof(Node));
    heap[0]->freq = 0;

    printf("Enter the number of characters: ");
    scanf("%d", &n);

    printf("Enter the characters and their frequencies: ");
    for (i = 0; i < n; i++) {
        scanf(" %c %d", &ch, &freq);
        temp = (Node *)malloc(sizeof(Node));
        temp->ch = ch;
        temp->freq = freq;
        temp->left = temp->right = NULL;
        Insert(temp);
    }

    if (n == 1) {
        printf("char %c code 0\n", heap[1]->ch);
        return 0;
    }

    for (i = 0; i < n - 1; i++) {
        Node *left = DeleteMin();
        Node *right = DeleteMin();
        temp = (Node *)malloc(sizeof(Node));
        temp->ch = 0;
        temp->left = left;
        temp->right = right;
        temp->freq = left->freq + right->freq;
        Insert(temp);
    }

    tree = DeleteMin();
    code[0] = '\0';
    print(tree, code);

    return 0;
}
