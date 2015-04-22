#include <stdio.h>

int main(){
	
	int n,resto,divisor,dividendo,mdc,i;

	scanf("%d",&n);

	scanf("%d",&mdc);

	for(i = 1; i < n; i++){
		scanf("%d",&divisor);
		dividendo = mdc;

		while(dividendo % divisor != 0){
			resto = dividendo % divisor;
			dividendo = divisor;
			divisor = resto;
		}

		mdc = divisor;
	}

	printf("MDC = %d\n",mdc);



	return 0;
}