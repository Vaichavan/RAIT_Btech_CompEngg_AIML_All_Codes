#include <stdio.h>
#include <conio.h> // for getch() in Turbo C

int count = 0;

int binS(int arr[], int l, int r, int x)
{
    count++;
    while (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    // If element is not found, return -1
    return -1;
}

int main()
{
    int arr[10], i, x, res;

    printf("Enter the elements in array: ");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    fflush(stdin); // Flush the input buffer

    printf("Enter the element to search: ");
    scanf("%d", &x);

    res = binS(arr, 0, 9, x);

    if (res == -1)
    {
        printf("Element not found.");
    }
    else
    {
        printf("Element found at index %d.", res);
    }

    printf("\nCount = %d", count);

    getch(); // Wait for a key press
    return 0;
}