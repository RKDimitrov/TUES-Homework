#include <stdio.h>

int sum(int* arr, int arrLen){
	if(arrLen > 0){
	    return arr[0] + sum(arr + 1, arrLen - 1);
	}else{
		return 0;
	}
}

int main(){
	int arrLen = 4;
	int arr[] = {5,2,3,7};
	printf("%d", sum(arr, arrLen));
	return 0;
}
