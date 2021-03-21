// Inversion Count
#include <stdio.h>

int naive_inversion_count(int A[], int n) {
  int inversion_count = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (A[i] > A[j]) {
        inversion_count = inversion_count + 1;
      }
    }
  }
  return inversion_count;
}

// in merge, A[low,...,mid] are sorted and A[mid + 1,...,high] are sorted
//calculate number of inversion 
int merge(int A[], int tmp[], int low, int mid, int high) {
  int i = low;
  int j = mid + 1;
  int inversionCount = 0;
  int k = low;
  while (i <= mid && j <= high) {
    if (A[i] > A[j]) { 
      // find inversions: A[i], A[i + 1]... A[mid] are all bigger than A[j]
      // i < j, i + 1 < j and mid < j, so increase inversionCount by (mid + 1 - i )
      inversionCount = inversionCount + (mid + 1 - i);
      tmp[k] = A[j];
      k++;
      j = j+1;
    } else {
      tmp[k] = A[i];
      k++;
      i = i+1;
    }
  }
  // moving remaining elements in Array A with i <= index <= mid to Array tmp
  while(i <= mid) {
    tmp[k] = A[i];
    k++;
    i++;
  }
  // moving remaining elements in Array A with j <= index <= high to Array tmp
  while(j <= high) {
    tmp[k] = A[j];
    k++;
    j++;
  }

  //move sorted elements from Array tmp to Array A
  for (i = low; i <= high; i++) {
    A[i] = tmp[i];
  }
  return inversionCount;
}

int mergeSort(int A[], int tmp[], int low, int high) {
  // base case, there is one single integer.
  if (low >= high) {
    return 0;
  }
  int mid = (low + high) / 2;
  int inversionCount = 0;
  //sort A[low,...,mid] and compute the number of inversion if A[low, ..., mid]
  inversionCount = inversionCount + mergeSort(A, tmp, low, mid);
  //sort A[mid + 1,..., high] and compute the number of inversion if A[mid + 1, ..., high]
  inversionCount = inversionCount + mergeSort(A, tmp, mid + 1, high);
  // calculate number of inversion in A[low, ..., high].
  inversionCount = inversionCount + merge(A, tmp, low, mid, high);
  return inversionCount;
}

int main() {
  int A[100];
  int tmp[100];
  int n = 0;
  printf("Values of the array separated by spaces (non-number to stop): ");
  while (scanf("%d", &A[n]) == 1) {
    n++;
  }
  scanf("%*s");
  printf("[Naive] Number of Inversions: %d\n", naive_inversion_count(A, n));
  printf("[Divide-Conquer] Number of Inversions: %d\n",
         mergeSort(A, tmp, 0, n - 1));
}