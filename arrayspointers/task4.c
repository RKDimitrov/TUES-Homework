#include <stdio.h>

void printarr(int arr[][4], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

void main()
{
    int arr[5][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}};
    printarr(arr, 5);
}