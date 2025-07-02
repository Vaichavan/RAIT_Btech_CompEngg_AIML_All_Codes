#include <stdio.h>

#define INFINITY 9999
#define MAX 10

void bellmanFord(int G[MAX][MAX], int n, int startNode);

int main() {
    int G[MAX][MAX], n, u ,i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    printf("\nEnter the starting node: ");
    scanf("%d", &u);

    bellmanFord(G, n, u);

    return 0;
}

void bellmanFord(int G[MAX][MAX], int n, int startNode) {
    int distance[MAX], pred[MAX];
    int i, u, v, j; // Declare variables here

    // Initialization
    for (i = 0; i < n; i++) {
        distance[i] = INFINITY;
        pred[i] = -1;
    }

    distance[startNode] = 0;

    // Relaxation
    for (i = 0; i < n - 1; i++) {
        for (u = 0; u < n; u++) {
            for (v = 0; v < n; v++) {
                if (G[u][v] != 0 && distance[u] + G[u][v] < distance[v]) {
                    distance[v] = distance[u] + G[u][v];
                    pred[v] = u;
                }
            }
        }
    }

    // Check for negative weights
    for (u = 0; u < n; u++) {
        for (v = 0; v < n; v++) {
            if (G[u][v] != 0 && distance[u] + G[u][v] < distance[v]) {
                printf("Graph contains negative weight cycle.\n");
                return;
            }
        }
    }

    // Display path
    for (i = 0; i < n; i++) {
        if (i != startNode) {
            printf("\nDistance of node %d = %d", i, distance[i]);
            printf("\nPath = %d", i);
            j = i;
            while (j != startNode) {
                j = pred[j];
                printf(" <- %d", j);
            }
            printf("\n");
        }
    }
}
