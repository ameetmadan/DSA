// Memoization sample code

#include <stdio.h>
#include <stdlib.h>

#define N 10
static size_t count = 0;

void iterativeFibonacci(int *resArray, int n)
{
    for (int i = 0; i < n; i++)
    {
        resArray[i] = i == 0 || i == 1 ? i : resArray[i - 1] + resArray[i - 2];
    }
}

/**
* Build a cache representing the Fibonacci sequence.
* Note that the second parameter is an array index which allows the cache to
* be checked for the required element. 
*/
int recursiveFibonacci(int *cache, int n)
{
    count++; // For analysis only

    // If the cache holds -1 at the required index, it has not yet been computed.
    if (cache[n] == -1)
    {
        cache[n] = recursiveFibonacci(cache, n - 1) + recursiveFibonacci(cache, n - 2);
    }
    return cache[n];
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(i == 0 ? "[ %d" : ", %d", arr[i]);
    }
    puts(" ]\n");
}

int main(void)
{
    int r[N];
    iterativeFibonacci(r, N);
    printArray(r, N);

    // Initialise an array of N elements, each element set to -1
    // Note that this is a GNU extension to the GCC compiler
    int cache[N] = {[0 ... N - 1] = -1};

    // Set the first two elements in the sequence, which are known
    cache[0] = 0;
    cache[1] = 1;

    // The function receives a pointer to the cache array and the index of the last element.
    recursiveFibonacci(cache, N - 1);
    printArray(cache, N);
    printf("recursiveFibonacci() called %lu times.\n", count);
    return 0;
}
