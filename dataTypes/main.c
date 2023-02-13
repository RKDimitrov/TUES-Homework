#include <stdio.h>
#include "quadraticroots.h"

int main(){
    struct QuadraticRootsResult q1;
    long double a = 5;
    long double b = 7;
    long double c = 1;

    q1 = findroots(a,b,c);

    if(q1.norealroots == 1){
        printf("There are no real roots");
    }else{
        printf("x1 = %llf\n", q1.x1);
        printf("x2 = %llf\n", q1.x2);
    }
}