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

void bubbleSort(int arr[], int n)
{
    for (int i = n; i > 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                int t = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = t;
            }
        }
    }
}

void bubbleSort2(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        //printf("outer loop %d \n",i);
        for (int j = n - 1; j >= i; j--)
        {
            //printf("->innter loop %d \n", j);
            if (arr[j] < arr[j - 1])
            {
                // printf("switch %d \n",arr[j]);
                int t = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = t;
            }
            printArray(arr, n);
        }
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort2(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}