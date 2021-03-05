/* Copied from https://github.com/JeromeHadorn/UZH_CS_Bachelor_Neuroinformatics/ */
#include <stdio.h>

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int n, int array[])
{
    int k;
    for (int i = 0; i < n - 1; i++)
    {
        k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[k])
            {
                k = j;
            }
        }
        // Possible improvement only if i != k
        // exchange i and k element
        int t = array[i];
        array[i] = array[k];
        array[k] = t;
    }
}

void selectionSort2(int n, int array[])
{
    int k;
    for (int i = n - 1; i > 1; i--)
    {
        k = i;
        for (int j = i - 1; j >= 0; j--)
        {
            if (array[j] > array[k])
            {
                k = j;
            }
        }
        // Possible improvement only if i != k
        // exchange i and k element
        int t = array[k];
        array[k] = array[i];
        array[i] = t;
    }
}

int main()
{
    int arr[] = {100, 64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort2(n, arr);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}