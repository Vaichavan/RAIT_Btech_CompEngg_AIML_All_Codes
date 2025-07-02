#include <stdio.h>
#include <string.h>

long comp = 0; // Change int to long

void naiveStringMatch(char* text, char* pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    int i,j;

    for (i = 0 ; i <= textLen - patternLen; i++) {
        for (j = 0 ; j < patternLen; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == patternLen) {
            printf("Pattern found at index %d\n", i);
        }
        comp++;
    }
}

int main() {
    char text[100], pattern[100]; // Increase array size for text and pattern

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    printf("Occurrences of the pattern:\n");

    naiveStringMatch(text, pattern);

    printf("Time Complexity: %ld\n", comp); // Change %d to %ld

    return 0;
}
