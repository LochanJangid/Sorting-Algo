#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);
void bubble_sort(int, int[]);

int main()
{
    // input - size of array
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    // Validate size of array
    if(n <= 0){
        printf("Invalid length.\n");
        return 1;
    }

    // input - n elements of array.
    int *arr = malloc(n * sizeof(int));

    // check if memory allocation failed.
    if(arr == NULL){
        printf("Allocation Failed.\n");
        return 1;
    }
    printf("Enter array: ");
    for (int i = 0; i < n; i++)
    {   
        if(scanf("%d", &arr[i]) != 1){
            printf("Invalid Input.\n");
            free(arr);
            return 1;
        }
    }

    bubble_sort(n, arr);
    

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

void bubble_sort(int n, int arr[n])
{
    int *p = arr;
    int *q = arr + 1;

    int decreasing_length = n - 1;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < decreasing_length; j++)
        {
            if (*p > *q)
                swap(p, q);
            p++;
            q++;
        }
        p = arr;
        q = arr + 1;
        decreasing_length--;
    }
}

void swap(int *p, int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}