#include <stdio.h>

int bsearch(int *arr, int left, int right, int nsearch){
	int mid = (left + right)/2;
	if(left >= right)return -1;
	if(nsearch == arr[mid])return mid;
	if(arr[mid] > nsearch){
		return bsearch(arr, left, mid, nsearch);
	}else{
		return bsearch(arr, mid, right, nsearch);
	}
}

int main(){
	int arrLen = 5;
	int arr[] = {1,2,3,4,5};
	int nsearch = 0;
	scanf("%d", &nsearch);
	printf("%d\n", bsearch(arr, 0, arrLen, nsearch));
}
