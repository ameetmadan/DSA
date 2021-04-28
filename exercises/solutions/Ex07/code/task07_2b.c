#include <stdio.h>
#define MAXSIZE 10

int queue[MAXSIZE];

int front = -1;
int rear = -1;
int size = -1;

int isempty()
{
    return size <= 0;
}

int isfull()
{
    return size == MAXSIZE;
}

void enqueue(int value)
{
    if(size<MAXSIZE)
    {
        if(isempty())
        {
            queue[0] = value;
            front = rear = 0;
            size = 1;
        }
        else if(rear == MAXSIZE-1)
        {
            queue[0] = value;
            rear = 0;
            size++;
        }
        else
        {
            queue[rear+1] = value;
            rear++;
            size++;
        }
    }
    else
    {
        printf("Queue is full\n");
    }
}

int Front()
{
    if(isempty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        return queue[front];
    }
}

int dequeue()
{
    int ret = Front();
    size--;
    front++;
    if (front == MAXSIZE) {
        front = 0;
    }
    return ret;
}

void display()
{
    if(isempty())
    {
        printf("Queue is empty\n");
        return;
    }

    int i;
    if(rear>=front)
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d,",queue[i]);
        }
    }
    else
    {
        for(i=front;i<MAXSIZE;i++)
        {
            printf("%d,",queue[i]);
        }
        for(i=0;i<=rear;i++)
        {
            printf("%d,",queue[i]);
        }
    }
		printf("\n");
}

int main()
{
    display();
    enqueue(4);
    enqueue(8);
    enqueue(10);
    enqueue(20);
    display();
    dequeue();
    printf("After dequeue\n");
    display();
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);
    dequeue();
    enqueue(90);
    enqueue(100);
    enqueue(110);
    enqueue(120);
    enqueue(130);
    enqueue(140);
    enqueue(150);
    printf("After enqueue\n");
    display();
    dequeue();
    printf("After dequeue\n");
    display();
    enqueue(160);
    printf("After enqueue\n");
    display();
    return 0;
}