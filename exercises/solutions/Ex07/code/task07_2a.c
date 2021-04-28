#include <stdio.h>
#define SIZE 10

int stack[SIZE];
int top = -1;

void push(int value)
{
    if(top<SIZE-1)
    {
        if (top < 0)
        {
            stack[0] = value;
            top = 0;
        }
        else
        {
            stack[top+1] = value;
            top++;
        }
    }
    else
    {
        printf("Stackoverflow!!!!\n");
    }
}

int isempty()
{
    return top<0;
}

int pop()
{
    if(!isempty())
    {
        int n = stack[top];
        top--;
        return n;
    } 
    else
    {
        printf("Error: the stack is empty!\n");
        return -99999;
    }
}

int Top()
{
    if (!isempty()) 
    {
        return stack[top];
    } 
    else 
    {
        printf("Error: the stack is empty!\n");
        return -99999;
    }
}

void display()
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%d,",stack[i]);
    }
    printf("\n");
}

int main()
{
    push(4);
    push(8);
    printf("isempty: %d\n", isempty());
    printf("Top: %d\n", Top());
    display();

    pop();
    printf("\nisempty: %d\n", isempty());
    printf("Top: %d\n", Top());
    display();

    pop();
    printf("\nisempty: %d\n", isempty());
    printf("Top: %d\n", Top());
    display();

    pop();

    return 0;
}