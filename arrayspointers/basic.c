#include <stdio.h>

int len(char str[])
{
    char *p = str;
    int len = 0;
    while(*(p++) != '\0'){
        len++;
    }
}

int main(){
    char str[6]= {"nikola"}

    printf("len: %d", len(str));
}