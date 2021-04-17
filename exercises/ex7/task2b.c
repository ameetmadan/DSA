#include <stdio.h>
#include <stdlib.h>
int A[10];
int t = 0;
int h = 0;
int n = 10;
int i;
int Q[10];

void enqueue(int x)
{
    A[t] = x;
    t = t + 1;
}

void dequeue(int x)
{
    i = h;
    h = (h + 1) % n;
    return Q[i];
}

int main()
{
    enqueue(0);
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue(4);
    dequeue(3);
    dequeue(2);
    dequeue(1);
    enqueue(0);
    return 0;
}