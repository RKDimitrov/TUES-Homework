#include <stdio.h>
#include <stdlib.h>

int compareasc(void *a, void *b){
    int *aptr = (int*)a;
    int *bptr = (int*)b;

    if(*aptr > *bptr){
        return 1;
    }else if(*aptr < *bptr){
        return -1;
    }else{
        return 0;
    }
}

int comparedesc(void *a, void *b){
    int *aptr = (int*)a;
    int *bptr = (int*)b;

    if(*aptr > *bptr){
        return -1;
    }else if(*aptr < *bptr){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int first_number;
    int second_number;

    scanf("%d", &first_number);
    scanf("%d", &second_number);

    void *firstptr = &first_number;
    void *secondptr = &second_number;

    printf("compareasc: %d\n", compareasc((void *)firstptr,(void *)secondptr));
    printf("comparedesc: %d\n", comparedesc((void *)firstptr,(void *)secondptr));

}