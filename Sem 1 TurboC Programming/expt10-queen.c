#include <stdio.h>

#define N_MAX 20 // Maximum number of queens (adjust as needed)

int comp = 0;

typedef enum { FALSE, TRUE } Bool;

void printSolution(int board[][N_MAX], int N) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
            comp++;
        }
        printf("\n");
    }
}

Bool isSafe(int board[][N_MAX], int row, int col, int N) {
    int i, j;
    // Check for queens in the same row
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return FALSE;
        }
    }
    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return FALSE;
        }
    }
    // Check lower diagonal on left side
    for (i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return FALSE;
        }
    }
    return TRUE;
}

Bool solveNQueens(int board[][N_MAX], int col, int N) {
    int i;
    if (col >= N) {
        return TRUE; // All queens are placed
    }
    for (i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1; // Place the queen
            if (solveNQueens(board, col + 1, N)) {
                return TRUE;
            }
            board[i][col] = 0; // Backtrack if placement leads to failure
        }
    }
    return FALSE; // No safe place found, backtrack
}

int main() {
    int N,i,j,board[N_MAX][N_MAX];
    printf("Enter the number of queens (up to %d): ", N_MAX);
    scanf("%d", &N);
    if (N < 1 || N > N_MAX) {
        printf("Invalid number of queens. Please enter a number between 1 and %d.\n", N_MAX);
        return 1;
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            board[i][j] = 0; // Initialize board with 0 (no queens)
        }
    }
    if (!solveNQueens(board, 0, N)) {
        printf("Solution does not exist\n");
    } else {
        printf("Solution to the %d Queens Problem:\n", N);
        printSolution(board, N);
    }
    printf("Time Complexity: %d\n", comp);
    return 0;
}
