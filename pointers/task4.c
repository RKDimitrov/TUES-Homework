#include <stdio.h>

void compare(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int bubblesort(int arr[], int n){
    int i, j;
    
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                compare(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main(){

}