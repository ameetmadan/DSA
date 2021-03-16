/* Copied from https://github.com/JeromeHadorn/UZH_CS_Bachelor_Neuroinformatics/ */

#include <stdio.h>
#include <math.h>

int binSearch(int arr[], int n, int v)
{
    int l = 0;
    int r = n - 1;
    int m;

    m = (int)floor((l + r) / 2);

    while (l <= r && v != arr[m])
    {
        if (v < arr[m])
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
        m = (int)floor((l + r) / 2);
    }

    if (l <= r)
    {
        return m;
    }
    else
    {
        return -1;
    }
}

int main()
{

    int v = 12;

    int arr[] = {11, 12, 22, 25, 36, 75, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = binSearch(arr, n, v);
    printf("index: %d \n", index);
    return 0;
}