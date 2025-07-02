#include <stdio.h>
#include <conio.h> // for getch() in Turbo C

void insertionSort(int arr[], int n, int *count) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            (*count)++; // Increment count for each comparison
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[100], n, i, count = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n, &count);

    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Complexity Count: %d\n", count);

    getch(); // Wait for a key press
    return 0;
}