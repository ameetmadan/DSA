#include <stdio.h>

void swap(int A[], int start, int end);
void heapSort(int A[], int length);
void heapify(int A[], int current_node, int length, int ascending);
void min_heapify(int A[], int i, int n);
void max_heapify(int A[], int i, int n);
void buildHeap(int A[], int length);
int lchild(int i);
int rchild(int i);

void heapSort(int A[], int length)
{
    // transform the input array into a valid heap
    buildHeap(A, length);

    int last_node_still_in_heap = length;
    int i;
    for (i = length - 1; i > 0; i--)
    {
        swap(A, i, 0);
        last_node_still_in_heap--;
        heapify(A, 0, last_node_still_in_heap, 0);
    }
}

void buildHeap(int A[], int length)
{
    int i;
    for (i = length / 2; i >= 0; i--)
    {
        heapify(A, i, length, 0);
    }
}

void heapify(int A[], int current_node, int length, int ascending)
{
    if (ascending == 1)
    {
        min_heapify(A, current_node, length);
    }
    else
    {
        max_heapify(A, current_node, length);
    }
}

void min_heapify(int A[], int i, int n)
{
    int min = i;
    int l = lchild(i);
    int r = rchild(i);

    if (l < n && A[l] < A[min])
    {
        min = l;
    }
    if (r < n && A[r] < A[min])
    {
        min = r;
    }

    if (min != i)
    {
        swap(A, i, min);
        heapify(A, min, n, 0);
    }
}

void max_heapify(int A[], int i, int n)
{
    int max = i;
    int l = lchild(i);
    int r = rchild(i);

    if (l < n && A[l] > A[max])
    {
        max = l;
    }
    if (r < n && A[r] > A[max])
    {
        max = r;
    }

    if (max != i)
    {
        swap(A, i, max);
        heapify(A, max, n, 0);
    }
}

void swap(int A[], int start, int end)
{
    int tmp;
    tmp = A[start];
    A[start] = A[end];
    A[end] = tmp;
}

void printArray(int A[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int lchild(int i)
{
    return 2 * i + 1;
}

int rchild(int i)
{
    return 2 * i + 2;
}

int main()
{
    int A[] = {11, 3, 73, 21, 99, 1000, 1002, 3, 1, 23};
    int n = sizeof A / sizeof *A;
    heapSort(A, n);
    printArray(A, n);
    return 0;
}