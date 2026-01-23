#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);
void selection_sort(int, int[]);

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
        // | This condition is work like scanf returns 1 if everything is ok
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid Input.\n");
            free(arr);
            return 1;
        }
    }

    selection_sort(n, arr);

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

void selection_sort(int n, int arr[n])
{
    for (int i = 0; i < n - 1; i++)
    {
        int *p = arr + i;
        int *q = p + 1;
        while (q < arr + n)
        {
            if (*p > *q)
            {
                p = q;
            }
            q++;
        }
        swap(arr + i, p);
    }
}

void swap(int *p, int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}