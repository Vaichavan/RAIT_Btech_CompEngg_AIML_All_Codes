#include <stdio.h>

int binarySearchRecursive(int arr[], int low, int high, int x) {
    if (low > high)
        return -1; // Element not found

    int mid = (low + high) / 2;

    if (x == arr[mid])
        return mid;
    else if (x > arr[mid])
        return binarySearchRecursive(arr, mid + 1, high, x);
    else
        return binarySearchRecursive(arr, low, mid - 1, x);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the sorted array elements: ");
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Enter the element to search: ");
    scanf("%d", &x);

    int result = binarySearchRecursive(arr, 0, size - 1, x);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}