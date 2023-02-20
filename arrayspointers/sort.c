#include <stdio.h>

void swap(int *a, int *b){
    int *temp = a; 
    a = b;
    b = temp;
}

int bubblesort(int *arr, int n){
    int i, j;
    
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if(*(arr + j) < *(arr + j + 1)) {
                swap(arr + j, arr + j + 1);
            }
        }
    }
}

int main(){
    int arr[5] = {1,2,2,4,75};
    int *p = arr;

    bubblesort(p, 5);
    for(int i = 0; i < 5; i++){
        printf("%d\n", arr[i]);
    }
}