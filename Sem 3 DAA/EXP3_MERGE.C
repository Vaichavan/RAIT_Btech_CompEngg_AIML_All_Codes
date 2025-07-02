#include <stdio.h>
#include <conio.h>

#define MAX_SIZE 100

int count = 0;

void merge(int arr[], int start, int mid, int end)
{
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int left[MAX_SIZE], right[MAX_SIZE];

    for (i = 0; i < n1; i++)
    {
	left[i] = arr[start + i];
    }

    for (j = 0; j < n2; j++)
    {
	right[j] = arr[mid + j + 1];
    }

    i = 0;
    j = 0;
    k = start;

    while (i < n1 && j < n2)
    {
	count++;
	if (left[i] <= right[j])
	{
	    arr[k] = left[i];
	    i++;
	}
	else
	{
	    arr[k] = right[j];
	    j++;
	}
	k++;
    }

    while (i < n1)
    {
	count++;
	arr[k] = left[i];
	i++;
	k++;
    }

    while (j < n2)
    {
	count++;
	arr[k] = right[j];
	j++;
	k++;
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
	int mid = start + (end - start) / 2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, start, mid, end);
    }
}

int main()
{
    int size;
    int array[MAX_SIZE];
    int i;

    //clrscr();

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > MAX_SIZE)
    {
	printf("Size exceeds maximum allowed size of %d.\n", MAX_SIZE);
	return 1;
    }

    printf("Enter %d values:\n", size);
    for (i = 0; i < size; i++)
    {
	scanf("%d", &array[i]);
    }

    mergeSort(array, 0, size - 1);

    printf("Sorted Array:\n");
    for (i = 0; i < size; i++)
    {
	printf("%d ", array[i]);
    }

    printf("\nCount = %d\n", count);

    getch();

    return 0;
}
