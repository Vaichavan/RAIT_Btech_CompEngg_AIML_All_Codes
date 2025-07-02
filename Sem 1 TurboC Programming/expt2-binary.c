#include <stdio.h>
int counter = 0;

int binarySearch(int arr[], int l, int r, int x) {
    counter++;

    if (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int main() {
    int arr[10], n,i,result, x;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the sorted array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    result = binarySearch(arr, 0, n - 1, x);

    if (result == -1) {
        printf("\nElement is not present in array");
    } else {
        printf("\nElement is present at index %d ", result);
    }

    printf("\nCounter: %d\n", counter);

    return 0;
}