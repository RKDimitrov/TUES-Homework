#include <stdio.h>


#define maxArrSize 500000

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

int binarySearch(int *arr, int arrSize, int diviation, int search){
    int left = 0, right = arrSize;

    while(left <= right){
        int mid = (left + right)/2;

        if((arr[mid] <= (search + diviation) && (arr[mid] >= search)) || (arr[mid] >= (search - diviation) && (arr[mid] <= search))){
            return mid;
        }else if (arr[mid] > search){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}

typedef struct{
	int x;
	int y;
} Point;

int nPointsInLasers(int* xLasers, int* yLasers, int laserWidth, int nLasers, Point* points, int nPoints){
	int counter = 0;
	for (int i = 0; i < nPoints; i++){
		if(binarySearch(xLasers, nLasers, laserWidth/2, points[i].x) != -1){
			counter++;
			continue;
		}
		if(binarySearch(yLasers, nLasers, laserWidth/2, points[i].y) != -1){
			counter++;
			continue;
		}
	}
	return counter;
}

int main(){
	int xLasers[maxArrSize] = {0};
	int yLasers[maxArrSize] = {0};
	Point points[maxArrSize];
	int nLasers = 0;
	int nPoints = 0;

	scanf("%d %d", &nLasers, &nPoints);

	for (int i = 0; i < nLasers; i++){
		scanf("%d %d", xLasers + i, yLasers + i);
	}

	for (int i = 0; i < nPoints; i++){
		scanf("%d %d", &(points[i].x), &(points[i].y));
	}

	int nReq = 0;
	scanf("%d", &nReq);

	for (int i = 0; i < nReq; i++){
		int laserWidth = 0;
		scanf("%d", &laserWidth);
		printf("%d ", nPointsInLasers(xLasers, yLasers, laserWidth, nLasers, points, nPoints));
	}
}
