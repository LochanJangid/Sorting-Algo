#include <stdio.h>
#include <stdlib.h>

void divide(int n, int arr[n]);
void merge_array(int len1, int len2, int arr1[len1], int arr2[len2], int n, int arr[n]);

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

    divide(n, arr);
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

void divide(int n, int arr[])
{

    int left_len = n / 2, right_len = n - left_len, i;
    int left[n / 2], right[n - n / 2];

    for (i = 0; i < n / 2; i++)
    {
        left[i] = arr[i];
    }
    if (left_len > 1)
        divide(left_len, left);

    for (int j = 0; j < n - n / 2; j++, i++)
    {
        right[j] = arr[i];
    }
    if (right_len > 1)
        divide(right_len, right);
    merge_array(left_len, right_len, left, right, n, arr);
}

void merge_array(int len1, int len2, int arr1[], int arr2[], int n, int arr[])
{
    // sorting two sorted arrays
    int i = 0;
    int j = 0;
    int index = 0;
    while (i < len1 && j < len2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[index++] = arr1[i];
            i++;
        }
        else
        {
            arr[index++] = arr2[j];
            j++;
        }
    }
    while (i < len1)
        arr[index++] = arr1[i++];
    while (j < len2)
        arr[index++] = arr2[j++];
}