#include <stdio.h>
int main(){
	int n = 1000;
	printf("Milhares abcd que possuem a raiz quadrada igual ab+cd:\n");
	while(n < 10000){
		if(((n/100) + (n%100)) * ((n/100) + (n%100)) == n){
			printf("%d ",n);
		}
		n++;
	}
	printf("\n");
	return 0;
}