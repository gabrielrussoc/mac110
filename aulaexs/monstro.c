#include <stdio.h>

int main(){
	int n,soma;

	scanf("%d",&n);
	soma = n;

	while(soma > 10){
		soma = 0;

		while (n > 0){
			soma += n%10;
			n = n/10;
		}

	n = soma;	

	}

	printf("%d\n",soma);


	return 0;
}