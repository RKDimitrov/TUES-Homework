#include <stdio.h>
#include "mystrings.h"

int strlenght(char *str1){
    int lenght = 0;
    for(lenght = 0; str1[lenght] != '\0'; lenght++);
    return lenght;
}

void strconcat(char *str1, char *str2){
    char str3[100];
    int j = 0;
    for(int i = 0; str1[i] != '\0'; i++){
        str3[j] = str1[i];
        j++;
    }
    for(int i = 0; str2[i] != '\0'; i++){
        str3[j] = str2[i];
        j++;
    }
    printf("%s",str3);
}

int strcompare(char *str1, char *str2){
    int i;
    for(i = 0; str1[i] == str2[i] && str1[i] != '\0' || str2[i] != '\0';i++);
    if(str1[i] < str2[i]){
        return -1;
    }else if(str1[i] > str2[i]){
        return 1;
    }else{
        return 0;
    }
}