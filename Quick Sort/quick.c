#include <stdio.h>
#include <stdlib.h>

void Quick_Sort(int a[], int *low, int *high);
int *Split(int a[], int *low, int *high);

int main()
{
    // input - size of array
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    // Validate size of array
    if (n < 1)
    {
        printf("Invalid length.\n");
        return 1;
    }

    // input - n elements of array.
    int *arr = malloc(n * sizeof(int));

    // check if memory allocation failed.
    if (arr == NULL)
    {
        printf("Allocation Failed.\n");
        return 1;
    }
    printf("Enter array: ");
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid Input.\n");
            free(arr);
            return 1;
        }
    }

    // Call QuickSort Function
    Quick_Sort(arr, arr, arr + (n-1));

    // print sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

void Quick_Sort(int a[], int *low, int *high)
{
    // Base Case:
    if (low >= high)
        return;

    int *middle;
    middle = Split(a, low, high);

    // Recursion
    Quick_Sort(a, low, middle - 1);
    Quick_Sort(a, middle + 1, high);
}

int *Split(int a[], int *low, int *high)
{
    int pivot = *low;

    while (1)
    {
        // number who is less than pitvot shift to left
        while (low < high && pivot <= *high)
            high--;
        if (low >= high)
            break;
        *low++ = *high;

        // number who is greater than pivot shift to right
        while (low < high && pivot >= *low)
            low++;
        if (low >= high)
            break;
        *high-- = *low;
    }
    *low = pivot;
    return low;
}