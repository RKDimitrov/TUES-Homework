#include <stdio.h>

int arrangeTowers(int* arr, int n){
    int isArranged = 0;
    while(!isArranged){
        for(int i = 0; i < n; i++){
            if(arr[i] >= (arr[i] - 1) || arr[i] <= (arr[i] + 1)){
                isArranged = 1;
                continue;
            }else{
                int c = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = c;
                isArranged = 0;
            }
        }
    }
}

int main(){
    int arrTowers[] = {0};
    int nTowers = 0;

    printf("Number of Towers:\n");
    scanf("%d", &nTowers);

    printf("Size of Towers:\n");
    for(int i = 0; i < nTowers; i++){
        scanf("%d", &arrTowers[i]);
    }

    arrangeTowers(arrTowers, nTowers);

    printf("Arranged Towers:\n");
    for(int i = 0; i < nTowers; i++){
        printf("%d", arrTowers[i]);
    }
}