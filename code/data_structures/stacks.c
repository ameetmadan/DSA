/* Copied from https://github.com/JeromeHadorn/UZH_CS_Bachelor_Neuroinformatics/ */

#include <stdlib.h>
#include <stdio.h>

int A[10];
int t = 0;

void printStack()
{
    for (int i = 0; i < t; i++)
    {
        printf("%d,", A[i]);
    }
}

void push(int x)
{
    A[t] = x;
    t++;
}

int pop()
{
    t--;
    return A[t];
}

int main()
{

    push(10);
    printStack();
    push(20);
    printStack();
    pop();
    printStack();
    return 0;
}