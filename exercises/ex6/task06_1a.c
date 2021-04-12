#include <stdio.h>

int main()
{
  char ch = 'a';
  int i = 1;
  double d = 1.2;
  char *p_ch = &ch;
  int *p_i = &i;
  double *p_d = &d;

  printf("The address of ch is %p \n", &ch);     /* 0x7ffeeed9966f */
  printf("The address of i is %p \n", &i);       /* 0x7ffeeed99668 */
  printf("The address of d is %p \n", &d);       /* 0x7ffeeed99660 */
  printf("The address of p_ch is %p \n", &p_ch); /* 0x7ffeeed99658 */
  printf("The address of p_i is %p \n", &p_i);   /* 0x7ffeeed99650 */
  printf("The address of p_d is %p \n", &p_d);   /* 0x7ffeeed99648 */

  printf("The value of ch is %c \n", ch);     /* a */
  printf("The value of i is %d \n", i);       /* 1 */
  printf("The value of d is %f \n", d);       /* 1.200000 */
  printf("The value of p_ch is %p \n", p_ch); /* 0x7ffeeed9966f - pointers don't have a value */
  printf("The value of p_i is %p \n", p_i);   /* 0x7ffeeed99668 - pointers don't have a value */
  printf("The value of p_d is %p \n", p_d);   /* 0x7ffeeed99660 - pointers don't have a value */

  printf("The size of ch is %zu bytes \n", sizeof(ch));     /* 1 bytes */
  printf("The size of i is %zu bytes \n", sizeof(i));       /* 4 bytes */
  printf("The size of d is %zu bytes \n", sizeof(d));       /* 8 bytes */
  printf("The size of p_ch is %zu bytes \n", sizeof(p_ch)); /* 8 bytes */
  printf("The size of p_i is %zu bytes \n", sizeof(p_i));   /* 8 bytes */
  printf("The size of p_d is %zu bytes \n", sizeof(p_d));   /* 8 bytes */
}
