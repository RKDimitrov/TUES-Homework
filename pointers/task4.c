#include <stdio.h>

int compareasc(const void *a,const void *b){
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

int comparedesc(const void *a,const void *b){
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

int bubblesort(int arr[], int n, int (*compare)(const void*,const void*)){
    int i, j;
    
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if(compare(&arr[j], &arr[j+1]) > 0) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int arr[] = {5, 7, 8, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubblesort(arr, n, compareasc);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    bubblesort(arr, n, comparedesc);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}