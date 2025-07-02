#include <stdio.h>
#include <string.h>
#include <conio.h>

int naiveStringMatcher(char T[], char P[], int *comparisons, int *iterations)
{
    int n = strlen(T);
    int m = strlen(P);
    int s, j;

    for (s = 0; s <= n - m; s++)
    {
        (*iterations)++;
        for (j = 0; j < m; j++)
        {
            (*comparisons)++;
            if (T[s + j] != P[j])
            {
                break;
            }
        }
        if (j == m)
        {
            return s;
        }
    }

    return -1;
}

int main()
{
    char T[] = "This is a test of a string";
    char P[] = "of";

    int shift;
    int comparisons = 0;
    int iterations = 0;

    clrscr();
    printf("Text: %s\n", T);
    printf("Pattern: %s\n", P);

    shift = naiveStringMatcher(T, P, &comparisons, &iterations);

    if (shift != -1)
    {
	printf("\nPattern found at shift %d\n", shift);
    }
    else
    {
	printf("\nPattern not found\n");
    }

    printf("\nTotal comparisons: %d\n", comparisons);
    printf("Total iterations: %d\n", iterations);

    getch(); // Wait for a key press before exiting

    return 0;
}