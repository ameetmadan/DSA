int main()
{
    int n = 8;
    int A[n] = {2, 3, 5, 7, 9, 13, 15, 27};
    int t = 20;
}

/* 
1. We divide length of array into 2 (n/2)
2. We check if element at index n/2 is greater or smaller than t
3a. If n/2 > t, we move left (n/2 - 1)
3b. If n/2 < t, we move right (n/2 + 1)
4. We now look at the problem again but just on the right or left part of the array (Recursion!)
5. Once we find the element where t fits in, we add it there.
*/

int divideAndConquer(A, n, t)
{
    int mid = A[n / 2];
    if (mid < t)
    {
        int B[] = {}; /* create new array here with elements from A[n/2] upto n */
    }
    else /* mid > t*/
    {
        int C[] = {}: /* create new array here with elements from A[0] upto A[n/2] */
    }
    divideAndConquer(B, C); /* run the function recursively on the two new created arrays */
}