#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bubbleSort(int* arr, int size){
    int isSorted = 0;
    while(!isSorted){
        isSorted = 1;
        for(int i = 0; i < size - 1; i++){
            if(arr[i] > arr[i+1]){
                int a = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = a;
                isSorted = 0;
            }
        }
    }
}

void bucketSort(int* arr, int size){
    int nOfBuckets = ceil(sqrt(size));
    int** buckets = (int**) calloc(nOfBuckets, sizeof(int*));
    int* bucketIndexes = (int*) calloc(nOfBuckets, sizeof(int));

    for(int i = 0; i < nOfBuckets; i++){
        buckets[i] = (int*) calloc(size, sizeof(int));
    }
    
    int min = arr[0];
    int max = arr[0];
    for(int i = 0; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
        }else if(arr[i] > max){
            max = arr[i];
        }
    }
    
    int bucketSize = ceil((max-min) / (float)nOfBuckets) + 1;
    for(int i = 0; i < size; i++){
        int bucketIndex = floor((arr[i] - min) / (float)bucketSize);
        buckets[bucketIndex][bucketIndexes[bucketIndex]] = arr[i];
        bucketIndexes[bucketIndex]++;
    }

    int arrIndex = 0;
    for(int i = 0; i < nOfBuckets; i++){
        bubbleSort(buckets[i], bucketIndexes[i]);
        for(int j = 0; j < bucketIndexes[i]; j++){
            arr[arrIndex] = buckets[i][j];
            arrIndex++;
        }
    }
}

int main(){
    int arr[] = {29, 25, 3, 49, 9, 37, 21, 43};
    int size = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, size);
    printf("Bucket Sorted: ");
    for(int i = 0; i < size; i++){
        printf("%d, ", arr[i]);
    }
}