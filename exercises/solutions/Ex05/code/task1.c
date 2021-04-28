#include <stdio.h>
  
void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void heapify(int A[], int i, int n) {
  int m = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && A[l] > A[m])
    m = l;

  if (r < n && A[r] > A[m])
    m = r;

  if (m != i) {
    swap(&A[i], &A[m]); // exchange A[i] and A[m];
    heapify(A, m, n);
  }
}

void buildHeap(int A[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(A, i, n);
}

void heapSort(int A[], int n) {
  buildHeap(A, n);

  for (int i = n - 1; i >= 0; i--) {
    swap(&A[0], &A[i]);
    heapify(A, 0, i);
  }
}

void display(int A[], int n) {
  for (int i = 0; i < n; ++i)
    printf("%d ", A[i]);
  printf("\n");
}

int main() {
  int A[] = {11, 34, 9, 5, 16, 10};
  int n = sizeof(A) / sizeof(A[0]);

  printf("Original Array:\n");
  display(A, n);
  
  buildHeap(A, n);
  printf("After buildHeap:\n");
  display(A, n);

  //optional, heap sort.
  heapSort(A, n);
  printf("[optional]Sorted array:\n");
  display(A, n);
}