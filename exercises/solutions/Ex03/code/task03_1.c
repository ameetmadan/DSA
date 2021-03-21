#include <stdio.h>
#include <stdlib.h>

int sumKBiggest(int a[], int n, int k) {
  int i, j, swp;
  int maxi;
  int sum = 0;
  
  for (i = 0; i < k; i++) {
    maxi = i;
    for (j = i + 1; j < n; j++) {
      if (a[j] > a[maxi]) { maxi = j; } //replace element with higher
    }
    sum += a[maxi]; //add kth biggest element to sum
    swp = a[i]; //swap to the left so it's not checked again
    a[i] = a[maxi];
    a[maxi] = swp;
  }
  return sum;
}

int main() {
  int A[] = {10, 12, 3, 4, 9, 7, 1, 25, 2, 1}; 
  int k = 4, n = 10;
  printf("k = %d\n", k);
  printf("sum = %d\n", sumKBiggest(A, k, n));
}

// Linux, Mac: gcc task03_1.c -lm -o task03_1; ./task03_1


