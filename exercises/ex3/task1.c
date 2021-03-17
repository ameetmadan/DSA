#include <stdio.h>

int whatIDo(int A[], int n, int k);

int main()
{
    int n;
    int k;
    int A[] = {1, 3, 5, 12, 16};
    printf("Enter array size n: ");
    scanf("%d", &n);
    printf("Enter integer k: ");
    scanf("%d", &k);
    whatIDo(&A[5], n, k);
}

int whatIDo(int A[], int n, int k)
{
    int i;
    int maxi;
    int j;
    int swp;
    int sum = 0;
    for (i = 1; i < k; i++)
        maxi = i;
    for (j = i + 1; i < n; i++)
        if (A[j] > A[maxi])
            maxi = j;
    sum = sum + A[maxi];
    swp = A[i];
    A[i] = A[maxi];
    A[maxi] = swp;
    return sum;
}
