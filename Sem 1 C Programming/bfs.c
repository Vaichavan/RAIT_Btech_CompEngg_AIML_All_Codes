#include <stdio.h>

int a[20][20], vis[20], queue[20];
int front = -1, rear = -1;

void bfs(int s, int n);

void enqueue(int item);
int dequeue();

int main() {
    int n, i, s, j;
    char c, dummy;

    printf("ENTER THE NUMBER VERTICES: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("ENTER 1 IF %d HAS A NODE WITH %d ELSE 0: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("THE ADJACENCY MATRIX IS\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }

    for (i = 1; i <= n; i++)
        vis[i] = 0;

    printf("ENTER THE SOURCE VERTEX: ");
    scanf("%d", &s);

    bfs(s, n);

    return 0;
}

void bfs(int s, int n) {
    int p, i;
    enqueue(s);
    vis[s] = 1;
    p = dequeue();

    if (p != 0) {
        printf(" %d ", p);
    }

    while (p != 0) {
        for (i = 1; i <= n; i++) {
            if (a[p][i] && !vis[i]) {
                enqueue(i);
                vis[i] = 1;
            }
        }
        p = dequeue();

        if (p != 0) {
            printf(" %d ", p);
        }
    }

    for (i = 1; i <= n; i++) {
        if (!vis[i]) {
            bfs(i, n);
        }
    }
}

void enqueue(int item) {
    if (rear == 19) {
        printf("QUEUE FULL");
    } else {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = item;
    }
}

int dequeue() {
    if (front > rear || front == -1) {
        return 0;
    } else {
        return queue[front++];
    }
}
