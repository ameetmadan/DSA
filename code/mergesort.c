/* Copied from https://github.com/JeromeHadorn/UZH_CS_Bachelor_Neuroinformatics/ */

#include <stdio.h>
#include <math.h>

void merge(int A[], int l, int r, int m);

void mergeSort(int A[], int l, int r)
{
    if (l < r)
    {
        int m = floor((l + r) / 2);
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, r, m);
    }
}

void printArray(int arr[], int size)
{
    int i = 0;
    while (i < size)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int A[], int l, int r, int m)
{
    int B[8];

    int bSize = 0;
    for (int i = l; i <= m; i++)
    {
        B[i] = A[i];
        bSize++;
    }
    for (int i = m + 1; i < r; i++)
    {
        B[r + m - i + 1] = A[i];
        //reverse filling
        bSize++;
    }

    printf("reversed array:");

    int nA = sizeof(B) / sizeof(B[0]);
    //printArray(B,nA);
    printf("%d", bSize);
    int i = l;
    int j = r;

    for (int k = l; k < r; k++)
    {
        if (B[i] < B[j])
        {
            A[k] = B[i];
            i = i + 1;
        }
        else
        {
            A[k] = B[j];
            j = j - 1;
        }
    }
}

int main()
{
    int A[] = {100, 64, 34, 25, 12, 22, 11, 90};
    int nA = sizeof(A) / sizeof(A[0]);
    mergeSort(A, 0, nA);

    for (int i = 0; i < nA; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}