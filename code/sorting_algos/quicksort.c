/* Copied from https://github.com/JeromeHadorn/UZH_CS_Bachelor_Neuroinformatics/ */

#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void QuickSort(int A[], int n, int l, int r)
{
    if (l < r)
    {
        int m = LomutoPartition(A, n, l, r); // || HoarePartition(A, n, l, r);
        QuickSort(A, n, l, m - 1);           // smallest Elements
        QuickSort(A, n, m + 1, r);           // largest Elements

        // Important no Merge needed at the end
    }
}

int LomutoPartition(int A[], int n, int l, int r)
{
    // pivot (Element to be placed at right position)
    int pivot = A[r]; // middle element (pivot) (we take rightmost element as middle element)
    int i = l - 1;
    for (int j = l; j < r - 1; j++)
    { // elements l..r-1 are inserted into either the smaller or larger part

        // If current element is smaller than the pivot
        if (A[j] < pivot)
        {
            i = i + 1; // increment index of smaller element
            swap(A[i], A[j]);
        }
        printf("%d, %d %d", i, j, pivot);
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

int HoarePartition(int A[], int n, int l, int r)
{
    int p = A[(l + r) / 2];
    int i = l - 1;
    int j = r + 1;
    while (1 == 1)
    {
        do
        {
            i++; // searches in the left part for a wrong (too large) element
        } while (A[i] < p);

        do
        {
            j--; // searches in the right part for a wrong (too small) element
        } while (A[j] > p);

        if (i >= j)
        {
            return j;
        }
        else
        {
            swap(&A[i], &A[j]); // Swap of "wrong" elements
        }
    }
    // int x = A[r];
    // int i = l - 1;
    // while (true)
    // {
    //     repeat j = j - 1 until A[j] < x; // searches in the right part for a wrong (too small) element
    //     repeat i = i + 1 until A[i] > x; // searches int he left part for a wrong (too large) element
    //     if (i < j)
    //     {
    //         swap(A[i], A[j]); // Swap of "wrong" elements
    //     }
    //     else
    //     {
    //         return i;
    //     }
    // }
}

int main()
{
    int A = {7, 8, 2, 6, 5, 1, 3};
    QuickSort(A, 7, 0, 6);
}