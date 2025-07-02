#include <stdio.h>
#include <string.h>
#include <conio.h>

#define MAX_LENGTH 100

int c[MAX_LENGTH + 1][MAX_LENGTH + 1];
char b[MAX_LENGTH + 1][MAX_LENGTH + 1];

int comparisons = 0, assignments = 0; // Counters for comparisons and assignments

void LCS_Length(char X[], char Y[], int m, int n)
{
    int i, j;
    for (i = 0; i <= m; i++)
    {
        c[i][0] = 0;
        assignments++; // Increment assignment counter
    }
    for (j = 0; j <= n; j++)
    {
        c[0][j] = 0;
        assignments++; // Increment assignment counter
    }

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            comparisons++; // Increment comparison counter
            if (X[i - 1] == Y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'd'; // diagonal
                assignments += 2; // Increment assignment counter for updating c and b
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'u'; // up
                assignments += 2; // Increment assignment counter for updating c and b
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l'; // left
                assignments += 2; // Increment assignment counter for updating c and b
            }
        }
    }
}

void Print_LCS(char X[], int i, int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }
    if (b[i][j] == 'd')
    {
        Print_LCS(X, i - 1, j - 1);
        printf("%c", X[i - 1]);
    }
    else if (b[i][j] == 'u')
    {
        Print_LCS(X, i - 1, j);
    }
    else
    {
        Print_LCS(X, i, j - 1);
    }
}

int main()
{
    char X[] = "ABCBDAB";
    char Y[] = "BDCAB";

    int m = strlen(X);
    int n = strlen(Y);

    LCS_Length(X, Y, m, n);

    printf("Length of LCS: %d\n", c[m][n]);
    printf("LCS: ");
    Print_LCS(X, m, n);
    printf("\n");

    printf("\nNumber of Comparisons: %d", comparisons);
    printf("\nNumber of Assignments: %d", assignments);

    getch(); // Wait for a key press before closing the console window

    return 0;
}
