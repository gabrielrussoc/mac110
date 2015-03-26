#include <stdio.h>
int main(){
	int n,i,j,mult = 0,cont = 0;
	printf("Vamos verificar os n primeiros multiplos de i e/ou j.\n");
	printf("Insira n, i e j:\n");
	scanf("%d %d %d", &n, &i, &j);
	printf("Os %d primeiros multiplos de %d e/ou %d sao: ",n,i,j);
	while(cont < n){
		if(mult%i == 0 || mult%j == 0){
			printf("%d ",mult);
			cont++;
		}
		mult++;
	}
	printf("\n");
	return 0;
}