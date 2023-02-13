#include "maths.h"
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char ** argv){
    int number = atoi(argv[1]);
    printf("%d", SQUARE(number));
}