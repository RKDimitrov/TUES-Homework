#include "safeint.h"
#include <stdio.h>
#include <stdlib.h>

struct SafeResult safeadd(int a,int b){
    struct SafeResult s1;
    s1.errorflag = 0;
    int number = s1.value;
    s1.value = a + b;
    if(s1.value < number){
        s1.errorflag = 1;
    }
    return s1;
}

struct SafeResult safesubtract(int a,int b)
{
    struct SafeResult s1;
    s1.errorflag = 0;
    int number = s1.value;
    s1.value = a - b;
    if(s1.value > number){
        s1.errorflag = 1;
    }
    return s1;
};


struct SafeResult safemultiply(int a,int b)
{
    struct SafeResult s1;
    s1.errorflag = 0;
    int number = s1.value;
    s1.value = a * b;
    if(s1.value < number){
        s1.errorflag = 1;
    }
    return s1;
};


struct SafeResult safedivide(int a,int b)
{
    struct SafeResult s1;
    s1.errorflag = 0;
    int number = s1.value;
    s1.value = a / b;
    if(s1.value > number){
        s1.errorflag = 1;
    }
    return s1;
};


struct SafeResult safestrtoint(char a)
{
    struct SafeResult s1;
    s1.errorflag = 0;
    int number = s1.value;
    s1.value = atoi(a);
    if(s1.value < number){
        s1.errorflag = 1;
    }
    return s1;
};