#include <stdio.h>

int main(){
	int num, soma;
	soma = 0;
	printf("Insira uma sequencia de numeros inteiros terminada por 0:\n");
	scanf("%d", &num);
	while (num != 0){
		soma = soma + num;
		scanf("%d", &num);
	}
	printf("Soma=%d\n",soma);
	return 0;	
}
