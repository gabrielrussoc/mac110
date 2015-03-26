#include <stdio.h>
int main(){
	int n, aux, num, soma = 0;
	printf("Insira um numero n: \n");
	scanf("%d",&n);
	printf("Insira uma sequencia de %d numeros:\n",n);
	while(n > 0){
		scanf("%d",&num);
		n--;
		if(num % 2 == 0){
			soma = soma + num;
		}
	}
	printf("A soma dos pares é: ");
	printf("%d\n",soma);
	return 0;
}