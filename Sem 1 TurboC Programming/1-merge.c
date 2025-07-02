#include <stdio.h>
#include <stdlib.h>

int count = 0;

void merge(int arr[], int l, int m, int r) {
    int i, j, k, n1, n2, L[10], R[10];
    n1 = m - l + 1;
    n2 = r - m;

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        count++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        count++;
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        count++;
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    int m;
    if (l < r) {
        m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int arr[10], n, i;
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        {scanf("%d", &arr[i]);}

    mergeSort(arr, 0, n - 1);

    printf("\nAfter sorting:\n");
    printArray(arr, n);

    printf("Counter: %d\n", count);

    return 0;
}