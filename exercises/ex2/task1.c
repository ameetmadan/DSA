#include <stdio.h>

int power(int x, int pow) /* C99 Compiler will throw an error if function is not defined before main function */
{
    /* base condition x != 0 */
    if (pow == 0)
    {
        return 1;
    }
    else
    {
        return x * power(x, pow - 1); /* we are calling the function power() inside the function again but reducing pow by 1 so that we can then multiply the result with x to give us our real result - this is an example of simple recrusion (sl01.pdf page 58/78) */
    }
}

int main()
{
    int x;
    int pow;

    printf("Please enter the base: ");
    scanf("%d", &x);

    printf("Please enter the power: ");
    scanf("%d", &pow);

    printf("The result is: %d", power(x, pow));
    return 0;
}
