#include <stdio.h>
#include "mystrings.h"

int main(int argc, char **argv){
    if(argc > 3){
        printf("Invalid arguments!");
    }else{
        if(strlenght(argv[1]) > 50 || strlenght(argv[2]) > 50 ) {
            printf("String is more then 50 chars");
        }else{
            strconcat(argv[1], argv[2]);  
        }
    }
}