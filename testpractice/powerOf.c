#include "maths.h"
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char ** argv){
    int number = atoi(argv[1]);
    int power = atoi(argv[2]);

    printf("%d", powerOf(number, power));
}