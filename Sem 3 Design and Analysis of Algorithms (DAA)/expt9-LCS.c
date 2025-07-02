#include <stdio.h>
#include <string.h>
#include <alloc.h>

int comp = 0;

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

void findLCS(char *X, char *Y, int m, int n) {
    int length, i, j;
    int **LCS;
    char *lcs;

    // Allocate memory for LCS array
    LCS = (int **)malloc((m + 1) * sizeof(int *));
    for (i = 0; i < m + 1; i++) {
        LCS[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    // Allocate memory for LCS string
    lcs = (char *)malloc((m + n + 1) * sizeof(char));

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            comp++;
        }
    }

    length = LCS[m][n];
    lcs[length] = '\0';

    i = m;
    j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[length - 1] = X[i - 1];
            i--;
            j--;
            length--;
        } else if (LCS[i - 1][j] > LCS[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("Longest Common Subsequence: %s\n", lcs);

    // Free allocated memory
    for (i = 0; i < m + 1; i++) {
        free(LCS[i]);
    }
    free(LCS);
    free(lcs);
}

int main() {
    char X[100], Y[100];
    int m, n;

    printf("Enter the first string: ");
    gets(X);
    printf("Enter the second string: ");
    gets(Y);

    m = strlen(X);
    n = strlen(Y);

    findLCS(X, Y, m, n);

    printf("Time Complexity: %d\n", comp);

    return 0;
}
