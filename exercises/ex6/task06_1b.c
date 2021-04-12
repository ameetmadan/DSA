#include <stdio.h>

void swap_nums(int *x, int *y)
{
  int tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

void swap_pointers(char **x, char **y) /* '**' means pointer to a pointer */
{
  char *tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

int main()
{
  int a, b;
  char *s1, *s2;
  a = 3;
  b = 4;
  swap_nums(&a, &b);
  printf("a is %d\n", a);
  printf("b is %d\n", b);
  s1 = "I should print second";
  s2 = "I should print first";
  swap_pointers(&s1, &s2);
  printf("s1 is %s\n", s1);
  printf("s2 is %s\n", s2);
  return 0;
}