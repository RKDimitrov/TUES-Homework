#include <stdio.h>

int power(int n, int m){
	if(m == 0)return 1;
	if(m == 1)return 2;
	return n * power(n,m-1);

}

int main(){
	int n = 0;
	int m = 0;
	scanf("%d", &n);
	scanf("%d", &m);
	printf("%d", power(n,m));
}
