#include <stdio.h>
#include <stdlib.h>

int partition(int A[], int l, int r) {
    int x = A[l], i = l;
    for (int j = l + 1; j <= r; j++) {
        if (A[j] <= x) {
            i += 1;
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    int t = A[i];
    A[i] = A[l];
    A[l] = t;
    return i;
}


int quickSelect(int A[], int l, int r, int index) {
    int q = partition(A, l, r);
    if (q == index) {
        return A[q];
    } else {
        return q < index ? quickSelect(A, q + 1, r, index)
                         : quickSelect(A, l, q - 1, index);
    }
}

int findKthLargest(int A[], int n, int k) {
    return quickSelect(A, 0, n - 1, n - k); // k-largest element are at index n - k
}

int main() {
  int n = 6, k = 3;
  int A[6] = {3,2,1,5,6,4};
  printf("%d\n", findKthLargest(A, n, k));

  int n = 9, k = 4;
  int A1[9] = {3,2,3,1,2,4,5,5,6};
  printf("%d\n", findKthLargest(A1, n, k));

  return 0;
}