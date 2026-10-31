#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high, int totalSize)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    printf("[PIVOT %d] placed at index %d: ", pivot, i + 1);
    printArray(arr, totalSize);

    return (i + 1);
}

void quickSort(int arr[], int low, int high, int totalSize)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, totalSize);
        quickSort(arr, low, pi - 1, totalSize);
        quickSort(arr, pi + 1, high, totalSize);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array: ");
    printArray(arr, n);
    printf("--------------------\n");

    quickSort(arr, 0, n - 1, n);

    printf("--------------------\n");
    printf("Final Sorted array: ");
    printArray(arr, n);

    return 0;
}