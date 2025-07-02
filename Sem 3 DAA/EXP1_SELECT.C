#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void selectionSort(int a[], int n);
void swap(int *x, int *y);
void sortedArray(int a[], int n);

int count = 0;

int main()
{
    int a[10], i;

   // clrscr();

    printf("Enter the elements of array: ");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }

    selectionSort(a, 10);
    sortedArray(a, 10);

    printf("\nCount = %d", count);

    getch(); // Wait for a key press
    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int a[], int n)
{
    int min, i, j;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            count++;
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(&a[min], &a[i]);
            count++;
        }
    }
}

void sortedArray(int a[], int n)
{
    int i;
    printf("Sorted array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}