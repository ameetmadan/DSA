#include <stdio.h>
 
int main() 
{
  char ch = 'a';
  int i = 1;
  double d = 1.2;
  char* p_ch = &ch;
  int* p_i = &i;
  double* p_d = &d;

  printf("The address of ch is %p \n", &ch);
  printf("The address of i is %p \n", &i);
  printf("The address of d is %p \n", &d);
  printf("The address of p_ch is %p \n", &p_ch);
  printf("The address of p_i is %p \n", &p_i);
  printf("The address of p_d is %p \n", &p_d);

  printf("The value of ch is %c \n", ch);
  printf("The value of i is %d \n", i);
  printf("The value of d is %f \n", d);
  printf("The value of p_ch is %p \n", p_ch);
  printf("The value of p_i is %p \n", p_i);
  printf("The value of p_d is %p \n", p_d);

  printf("The size of ch is %zu bytes \n", sizeof(ch));
  printf("The size of i is %zu bytes \n", sizeof(i));
  printf("The size of d is %zu bytes \n", sizeof(d));
  printf("The size of p_ch is %zu bytes \n", sizeof(p_ch));
  printf("The size of p_i is %zu bytes \n", sizeof(p_i));
  printf("The size of p_d is %zu bytes \n", sizeof(p_d));
}
 