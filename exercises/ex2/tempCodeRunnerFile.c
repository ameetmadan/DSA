#include <stdio.h>
#include <string.h>

int iterativeFirstUpper(char str[])
{
    char ch;
    int i;
    for (i = 0; i < strlen(str); i++) /* iterate over string characters */
    {
        if (ch >= 'A' && ch <= 'Z') /* check for all uppercase chars */
        {
            return str[i];
            printf("Uppercase char found at index %d \n", i);
        }
        else
        {
            return -1;
        }
    }
    return 0;
}

int main()
{
    iterativeFirstUpper("uppErcase");
}