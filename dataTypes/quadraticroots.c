#include <stdio.h>
#include "quadraticroots.h"
#include <math.h>

struct QuadraticRootsResult findroots(long double a, long double b, long double c){
    struct QuadraticRootsResult q1;

    long double discriminant = b*b - 4*a*c;

    if(discriminant < 0 ){
        q1.norealroots = 1;
        return q1;
    }else{
        q1.norealroots = 0;
        q1.x1 = (-b+sqrtl(discriminant))/(a*2);
        q1.x2 = (-b-sqrtl(discriminant))/(a*2);
    }
    
    return q1;
}