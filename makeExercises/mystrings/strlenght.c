#include <stdio.h>
#include "mystrings.h"

int main(int argc, char **argv){
    if(argc > 2){
        printf("Invalid argument!");
    }else{
        printf("String is: %d in lenght", strlenght(argv[1]));
    }
}