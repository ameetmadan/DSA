#include <stdio.h>
#include <stdlib.h>

int recursiveFirstUpper(char str[], int pos)
{
    if (str[pos] == '\0')
    {
        return -1;
    }
    if (str[pos] >= 'A' && str[pos] <= 'Z')
    {
        return pos;
    }
    return recursiveFirstUpper(str, pos + 1);
}

int main()
{
    printf("Please enter a string: ");
    char s[1000];
    scanf("%[^\n]s", s);
    printf("Result From Recursive Function: %d\n", recursiveFirstUpper(s, 0));
}
// Linux, Mac: gcc task3.c -o task3; ./task3