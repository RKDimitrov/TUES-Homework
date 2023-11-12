#include <stdio.h>

#define arrMaxSize 1000

int bubbleSort(int *arr, int arrSize){
    int isSorted = 0;
    while(!isSorted){
        isSorted = 1;
        for(int i = 0; i < arrSize - 1; i++){
            if(arr[i] > arr[i + 1]){
                int buffer = arr[i + 1];
                arr[i+1] = arr[i];
                arr[i] = buffer;
                isSorted = 0;
            }
        }
    }
}

int binarySearch(int *arr, int arrSize, int search){
    int left = 0, right = arrSize;
    
    while(left <= right){
        int mid = (left + right)/2;

        if(arr[mid] == search){
            return mid;    
        }else if (arr[mid] > search){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}

int cBBI(int * arr, int nBoxes){
    for(int i = 1; i < nBoxes; i++){
        if(arr[nBoxes - 1] > arr[nBoxes - i - 1]){
            return i;
        }
    }
    return -1;
}

int main(){
    int nBoxes = 0;
    int boxSizes[arrMaxSize] = {0};

    scanf("%d", &nBoxes);

    for(int i = 0; i < nBoxes; i++){
        scanf("%d", &boxSizes[i]);
    }

    bubbleSort(boxSizes, nBoxes);

    printf("%d\n", cBBI(boxSizes, nBoxes));
}