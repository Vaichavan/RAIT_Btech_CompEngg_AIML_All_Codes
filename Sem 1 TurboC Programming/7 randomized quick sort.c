#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to partition the array
int partitionLeft(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    int j;
    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, i, high);
    return i;
}

// Function to perform random partition
int partitionRight(int arr[], int low, int high) {
    int r;
    srand(time(0));
    r = low + rand() % (high - low);
    swap(arr, r, high);
    return partitionLeft(arr, low, high);
}

// Recursive function for quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int p = partitionRight(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code
int main() {
    int arr[] = {6, 4, 12, 8, 1, 0, 67, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);
    quicksort(arr, 0, n - 1);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}

