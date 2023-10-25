#include <stdio.h>

int palindrome(char* string, int strLen){
	if(strLen < 2){
		return 1;
	}
	if(string[0] == string[strLen - 1]){
		return palindrome(string + 1, strLen - 2);
	}else{
		return -1;
	}
}

int main(){
	int strLen = 7;
	char string[8] = "racecar";
	printf("%d\n", palindrome(string, strLen));
}
