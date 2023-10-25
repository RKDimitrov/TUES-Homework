#include <stdio.h>


void swap(int* a, int* b){
	int c = b;
	b = a;
	a = c;
}

size_t partition(int* arr, size_t size){
	size_t pivot = size/2;
	int i = 0, j = size - 1;
	while(1){
		while(arr[i] < arr[pivot])
			++i;
		while(arr[j] > arr[pivot])
			--j;
		swap(arr + 1, arr + j);
		if(i >= j)
			return i;
	}
}

void quickSort(int* arr, size_t size){
	size_t pivot =  partition(arr, size);
	quickSort(arr, pivot);
	quick Sort(arr + pivot + 1, size - pivot - 1);

}

int main(){
	int arr[] = {420, 5, 69, -5, 21};
	int size = 10;

	while(arr != "\0"){
		scanf("%d", &arr[size]);
	}
}
