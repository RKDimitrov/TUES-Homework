#include <stdio.h>

int factoriel(int n){
	if(n == 0)return 1;
	return n * factoriel(n-1);
}

int main(){
	int n = 0;
	scanf("%d", &n);
	printf("%d", factoriel(n));
}
