#include <stdio.h>
int main(){
	int n, soma = 0, divisor;
	printf("Digite um numero: \n");
	scanf("%d",&n);
	divisor = n/2 + 1;
	while (divisor > 0){
		if (n % divisor == 0){
			soma = soma + divisor;
		}
		divisor--;	
	}
	if (soma == n && soma != 1){
		printf("%d eh perfeito.\n",n);
	} else {
		printf("%d nao eh perfeito.\n",n);
	}
	return 0;
}