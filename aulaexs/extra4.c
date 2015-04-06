#include <stdio.h>

int main(){
	
	int divisor, dividendo, resto, i;

	printf("Insira dois inteiros\n");
	scanf("%d %d",&divisor,&dividendo);

	while(dividendo % divisor > 0){
		resto = dividendo % divisor;
		dividendo = divisor;
		divisor = resto;
	}

	printf("MDC = %d\n",divisor);

	return 0;
}