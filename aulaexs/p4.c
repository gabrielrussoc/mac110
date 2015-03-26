#include <stdio.h>

int main(){
		
	int n, num, soma;
	soma = 0;

	printf("Entre com n\n");
	scanf("%d",&n);
	printf("Entre com %d numeros:\n",n);

	while(n > 0){
		scanf("%d",&num);
		if(num > 0){
			soma = soma + num;
		}
		n = n - 1;
	}

	printf("Soma = %d\n",soma);

	return 0;
}