#include <stdio.h>
#include <conio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int low, int high) {
    int pivot = A[low];
    int i = low;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (A[i] <= pivot && i <= high);

        do {
            j--;
        } while (A[j] > pivot);

        if (i >= j)
            break;

        swap(&A[i], &A[j]);
    }

    swap(&A[low], &A[j]);
    return j;
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int m = partition(A, low, high);
        quickSort(A, low, m - 1);
        quickSort(A, m + 1, high);
    }
}

int main() {
    int n, i;
    int A[100];

    clrscr();

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    quickSort(A, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    getch(); // Wait for a key press before closing
    return 0;
}

