// Find the closest number in a sorted array
#include <stdio.h>
#include <stdlib.h>

int find_closer_in_two_values(int a, int b, int t) {
  if (abs(a - t) < abs(b - t)) {
    return a;
  }
  return b;
}

int find_closest(int A[], int n, int t) {
  if (t <= A[0]) {
    return A[0];
  }
  if (t >= A[n - 1]) {
    return A[n - 1];
  }
  // Now perform binary search
  int i = 0;
  int j = n;
  int mid = 0;
  while (i < j) {
    mid = (i + j) / 2;
    if (t == A[mid]) {
      return A[mid];
    }
    if (t < A[mid]) {
      // In this case, target is smaller than A[mid], all elements 
      //after index mid  are exclude. Binary search paradigm is applied.

      if (mid > 0 && t > A[mid - 1]) {
        // when A[mid - 1] > t, we can determine that the closest number to
        // t is either A[mid] or A[mid - 1]
        return find_closer_in_two_values(A[mid - 1], A[mid], t);
      }
      
      // we can't determine the closest number, so we continue to our search
      // between indice i and j = mid.
      j = mid;
    } else {
      // In this case, target is larger than x[mid], all elements 
      //before index mid are exclude. Binary search paradigm is applied.

      if (mid < n - 1 && t < A[mid + 1]) {
        // when A[mid + 1] < t, we can determine that the closest number to
        // t is either A[mid] or A[mid + 1]
        return find_closer_in_two_values(A[mid], A[mid + 1], t);
      }

      // we can't determine the closest number, so we continue to our search
      // between indice i = mid + 1 and j
      i = mid + 1;
    }
  }
  // after the search, there is only one element left
  return A[mid];
}

int main() {
  int A[100];
  int i = 0;
  int t = 0;
  int n = 0;
  printf("Values of the array separated by spaces (non-number to stop): ");

  while (scanf("%d", &A[i]) == 1) {
    i++;
  }
  n = i;
  scanf("%*s");
  printf("Target t: ");
  scanf("%d", &t);

  printf("Result: ");

  printf("%d\n", find_closest(A, n, t));
  return 0;
}

// Linux, Mac: gcc task04_1.c -o task04_1; 
// ./task04_1
