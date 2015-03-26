#include <stdio.h>
int main(){
	int n, soma;
	soma = 0;
	printf("Digite um numero:\n");
	scanf("%d",&n);
	while(n>=1){
		soma = soma + n;
		n = n-1;
	}
	printf("Resultado: %d\n",soma);
	return 0;
}