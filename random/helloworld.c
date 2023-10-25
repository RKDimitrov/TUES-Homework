#include <stdio.h>

int main(){
        char alphabet[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j','k','l','m', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 32};
	char word[20] = "hello world";
	char newword[20];
	int lengthofarr = sizeof(word) / sizeof(word[0]);	
	int i = 0;

	while(word[i] != '\0'){
		for(int j = 0; j < 27; j++){
			if (word[i] == alphabet[j]){
				newword[i] = alphabet[j];
				printf("%s\n", newword);
				break;
			}else{
				newword[i] = alphabet[j];
				printf("%s\n", newword);
			}
		}
	i++;	
	}
}
