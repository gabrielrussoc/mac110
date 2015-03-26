#include <stdio.h>
int main(){
	int n, soma = 0, cont = 1;
	printf("Insira um numero binario:\n");
	scanf("%d",&n);
	while(n > 0){
		soma = (n%10 * cont) + soma;
		cont = cont * 2;
		n = n/10;
	}
	printf("Na base decimal:%d\n",soma);
	return 0;
}