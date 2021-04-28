/*  C Program to implement Deque using circular array  */

#include <stdio.h>
#include <stdlib.h>
#define MAX 7

int deque_arr[MAX];
int front = -1;
int rear = -1;

void insert_frontEnd(int item);
void insert_rearEnd(int item);
int delete_frontEnd();
int delete_rearEnd();
void display();
int isEmpty();
int isFull();

int main()
{
  insert_rearEnd(5);
  insert_frontEnd(12);
  insert_rearEnd(11);
  insert_frontEnd(5);
  insert_rearEnd(6);
  insert_frontEnd(8);

  printf("\nElements in a deque: ");
  display();

  int i = delete_frontEnd();
  printf("\nremoved item: %d", i);

  printf("\nElements in a deque after deletion: ");
  display();

  insert_rearEnd(16);
  insert_rearEnd(7);

  printf("\nElements in a deque after addition: ");
  display();

  printf("\nInsert when full: ");
  insert_rearEnd(7);

  i = delete_rearEnd();
  printf("\nremoved item: %d", i);

  printf("\nElements in a deque after deletion: ");
  display();
} /*End of main()*/

void insert_frontEnd(int item)
{
  if (isFull())
  {
    printf("\nQueue Overflow\n");
    return;
  }
  if (front == -1) /*If queue is initially empty*/
  {
    front = 0;
    rear = 0;
  }
  else if (front == 0)
    front = MAX - 1;
  else
    front = front - 1;
  deque_arr[front] = item;
} /*End of insert_frontEnd()*/

void insert_rearEnd(int item)
{
  if (isFull())
  {
    printf("\nQueue Overflow\n");
    return;
  }
  if (front == -1) /*if queue is initially empty*/
  {
    front = 0;
    rear = 0;
  }
  else if (rear == MAX - 1) /*rear is at last position of queue */
    rear = 0;
  else
    rear = rear + 1;
  deque_arr[rear] = item;
} /*End of insert_rearEnd()*/

int delete_frontEnd()
{
  int item;
  if (isEmpty())
  {
    printf("\nQueue Underflow\n");
    exit(1);
  }
  item = deque_arr[front];
  if (front == rear) /*Queue has only one element */
  {
    front = -1;
    rear = -1;
  }
  else if (front == MAX - 1)
    front = 0;
  else
    front = front + 1;
  return item;
} /*End of delete_frontEnd()*/

int delete_rearEnd()
{
  int item;
  if (isEmpty())
  {
    printf("\nQueue Underflow\n");
    exit(1);
  }
  item = deque_arr[rear];

  if (front == rear) /*queue has only one element*/
  {
    front = -1;
    rear = -1;
  }
  else if (rear == 0)
    rear = MAX - 1;
  else
    rear = rear - 1;
  return item;
} /*End of delete_rearEnd() */

int isFull()
{
  if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    return 1;
  else
    return 0;
} /*End of isFull()*/

int isEmpty()
{
  if (front == -1)
    return 1;
  else
    return 0;
} /*End of isEmpty()*/

void display()
{
  int i;
  if (isEmpty())
  {
    printf("\nQueue is empty\n");
    return;
  }
  printf("\nQueue elements :\n");
  i = front;
  if (front <= rear)
  {
    while (i <= rear)
      printf("%d ", deque_arr[i++]);
  }
  else
  {
    while (i <= MAX - 1)
      printf("%d ", deque_arr[i++]);
    i = 0;
    while (i <= rear)
      printf("%d ", deque_arr[i++]);
  }
  printf("\n");
} /*End of display() */