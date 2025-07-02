#include <stdio.h>

void selectionSort(int A[], int n) {
    int i, j; // Declare loop variables here
    for (i = 0; i < n - 1; ++i) {
        int min = A[i];
        int loc = i;

        for (j = i + 1; j < n; ++j) {
            if (A[j] < min) {
                min = A[j];
                loc = j;
            }
        }

        if (loc != i) {
            // Swap A[i] and A[loc]
            int temp = A[i];
            A[i] = A[loc];
            A[loc] = temp;
        }
    }
}

int main() {
    int n, i, A[50]; // Declare loop variable here
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }

    // Perform selection sort
    selectionSort(A, n);

    // Display sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    return 0;
}
