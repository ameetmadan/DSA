/* Copied from https://github.com/JeromeHadorn/UZH_CS_Bachelor_Neuroinformatics/ */

#include <stdio.h>

#define n 5

int i, v;
int a[] = {11, 1, 4, -3, 22};

int main()
{
    i = 0;
    v = -3;
    while (i < n && a[i] != v)
    {
        i++;
    }
    if (i < n)
    {
        printf("Index is %d\n", i);
    }
    else
    {
        printf("NIL\n");
    }
    return 0;
}