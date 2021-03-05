/* Copied from https://github.com/JeromeHadorn/UZH_CS_Bachelor_Neuroinformatics/ */

#include <stdio.h>

void insertionSort(int n, int array[])
{
    for (int i = 1; i < n; i++)
    {

        int j = i - 1;
        int value = array[i];

        while (j >= 0 && array[j] > value)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = value;
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {100, 64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(n, arr);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}