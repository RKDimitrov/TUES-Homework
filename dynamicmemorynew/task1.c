#include <stdio.h>
#include <stdlib.h>

int avg(int* marks, int n){
    int avgmark = 0;
    for(int i = 0; i < n; i++){
        avgmark = *marks / n;        
    }
    return avgmark;
}

int newMark(int newMark,int* marks, int n){
    *marks = (int*)realloc(n + 1, n);
    *marks + 1 = newMark;

    return *marks, n;
}

int main(){
    int n = 0;
    int *p = &n;
    int options = 0;

    printf("Ocenkite ti: ");
    scanf("%d", &n);

    int* marks = (int*)calloc(n, sizeof(int));

    printf("Kakvi sa ti ocenkite:");
    for(int i = 0; i < n; i++){
        scanf("%d", &marks[i]);
    }
    switch (options)
    {
    case 0:
        printf("Option ");
        break;
    
    default:
        break;
    }
}