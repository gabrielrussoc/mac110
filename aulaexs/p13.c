#include <stdio.h>

int main(){
	
	int n,mdc,divisor,dividendo,resto,i;

	printf("Insira n:\n");
	scanf("%d",&n);
	printf("Insira n numeros:\n");
	scanf("%d",&mdc);

	for(i = 1; i < n; i++){

		divisor = mdc;
		scanf("%d",&dividendo);

		while(dividendo % divisor > 0){
			resto = dividendo % divisor;
			dividendo = divisor;
			divisor = resto;
		}

		mdc = divisor;

	}

	printf("O MDC eh %d\n",mdc);


	return 0;
}