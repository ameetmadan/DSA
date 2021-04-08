#include <stdio.h>
int calculateLength(char*);
 
int main() 
{
  char str1[100];
  int l;
	printf("\n\n Pointer : Calculate the length of the string :\n"); 
	printf("---------------------------------------------------\n");
   
  printf(" Input a string : ");
  fgets(str1, sizeof str1, stdin);
  
  l = calculateLength(str1);
  printf(" The length of the given string %s is : %d ", str1, l-1);
  printf("\n\n");

}
 
int calculateLength(char* ch) // ch = base address of array str1 ( &str1[0]  )
{
  int ctr = 0;
  while (*ch != '\0') 
  {
    ctr++;
    ch++;
  }
  return ctr;
}
