#include <stdio.h>

int main(){
    
    int a=0,b=0;

    scanf("%d", &a);
    scanf("%d", &b);

    int * pa = &a;
    int * pb = &b;

    printf("Address: %p\nValue: %d\n", &pa, *pa);
    printf("Address: %p\nValue: %d\n", &pb, *pb);

}