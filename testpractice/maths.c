#include "maths.h"
#include <stdio.h>

int powerOf(int number, int power){
    int result = 1;
    for (int i = 0; i < power; i++){
        result = number * result;
    }
    return result;
}