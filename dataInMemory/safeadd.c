#include <stdio.h>
#include "safeint.h"

int main(int argc, char **argv){
    int a = argv[1];
    int b = argv[2];
    safeadd(a,b);
}