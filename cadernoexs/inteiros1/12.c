#include <stdio.h>

int main(){
	
	int divisor, dividendo, resto;

	printf("Entre com 2 numeros:\n");
	scanf("%d %d",&divisor,&dividendo);

	while(dividendo%divisor){
		resto = dividendo%divisor;
		dividendo = divisor;
		divisor = resto;
	}

	printf("%d\n",divisor);


	return 0;
}