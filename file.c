#include <stdio.h>

void strcompare(char *str1, char *str2);

int main(){
    char str1[50] = "zdrastiw";
    char str2[50] = "zdrastiw";

    strcompare(str1,str2);

}

void strcompare(char *str1, char *str2){
    int i;
    for(i = 0; str1[i] == str2[i] && str1[i] != '\0' || str2[i] != '\0';i++);
    if(str1[i] < str2[i]){
        printf("str1 is less then str2");
    }else if(str1[i] > str2[i]){
        printf("str2 is less then str1");
    }else{
        printf("the strings are equal");
    }
}