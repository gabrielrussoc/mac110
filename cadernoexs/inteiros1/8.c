#include <stdio.h>
int main(){
	int n, aux, fat;
	fat = 1;
	printf("Insira um numero:\n");
	scanf("%d",&n);
	aux = n;
	while(aux>=1){
		fat = fat * aux;
		aux = aux-  1;
	}
	printf("%d! = %d\n",n,fat);
	return 0;
}