#include <stdio.h>

void strHalf(char *str, char **half)
{
    char *ptr = str;
    int len = 0;
    while (*(ptr++) != '\0')
    {
        len++;
    }
    *half = str + len / 2;
}

void main()
{
    char str[] = "test";
    char *half;
    strHalf(str, &half);
    printf("%s", half);
}