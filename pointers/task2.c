#include <stdio.h>
#include <string.h>

void main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    char *pos;
    if ((pos = strchr(str, '\n')) != NULL)
    {
        *pos = '\0';
    }
    printf("The string is: %s", str);
}