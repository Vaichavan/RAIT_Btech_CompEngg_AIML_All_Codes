#include <stdio.h>
#include <conio.h>

#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void printSelectedItems(int V[MAX][MAX], int w[], int v[], int n, int W) {
    int i = n;
    int weight = W;

    printf("Selected items:\n");
    while (i > 0 && weight > 0) {
        if (V[i][weight] != V[i - 1][weight]) {
            printf("Item %d (Value: %d, Weight: %d)\n", i, v[i - 1], w[i - 1]);
            weight -= w[i - 1];
        }
        i--;
    }
}

int knapsack(int v[], int w[], int n, int W) {
    int V[MAX][MAX];
    int i, weight;

    // Initialize the first row and first column to 0
    for (weight = 0; weight <= W; weight++) {
        V[0][weight] = 0;
    }

    for (i = 1; i <= n; i++) {
        for (weight = 0; weight <= W; weight++) {
            if (w[i - 1] <= weight) {
                V[i][weight] = max(V[i - 1][weight], v[i - 1] + V[i - 1][weight - w[i - 1]]);
            } else {
                V[i][weight] = V[i - 1][weight];
            }
        }
    }

    // Print selected items
    printSelectedItems(V, w, v, n, W);

    return V[n][W];
}

void main() {
    int v[MAX], w[MAX], n, W, i;
    clrscr();  // Clear screen for Turbo C++

    // Input number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Input value and weight of each item
    printf("Enter the value and weight of each item:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d value: ", i + 1);
        scanf("%d", &v[i]);
        printf("Item %d weight: ", i + 1);
        scanf("%d", &w[i]);
    }

    // Input maximum capacity of knapsack
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);

    // Call knapsack function and display the result
    printf("Maximum value in Knapsack = %d\n", knapsack(v, w, n, W));

    getch();  // Wait for user input before closing
}

