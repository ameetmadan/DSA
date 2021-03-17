#include <stdio.h>
#include <stdlib.h>

int strLength(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

int iterativeFirstUpper(char str[])
{
    int i;
    for (i = 0; i < strLength(str); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    printf("Please enter a string: ");
    char s[1000];
    scanf("%[^\n]s", s);
    printf("Result From Iterative Function: %d\n", iterativeFirstUpper(s));
}
// Linux, Mac: gcc task3.c -o task3; ./task3