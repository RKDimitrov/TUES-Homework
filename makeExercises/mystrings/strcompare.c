#include <stdio.h>
#include "mystrings.h"

int main(int argc, char **argv){
     if(argc > 3){
        printf("Invalid arguments!");
    }else{
        printf("%d", strcompare(argv[1],argv[2]));  
    }
}
