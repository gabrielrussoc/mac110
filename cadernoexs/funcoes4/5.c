#include <stdio.h>

int calcMdc(int a, int b){

	int divisor, dividendo, resto;
	divisor = a;
	dividendo = b;

	while(dividendo % divisor){
		resto = dividendo % divisor;
		dividendo = divisor;
		divisor = resto;
	}

	return divisor;

}


int main(){

	int n, mdc, num, i;

	scanf("%d",&n);
	scanf("%d",&mdc);

	for(i = 1; i < n; i++){
		scanf("%d",&num);
		mdc = calcMdc(mdc,num);
	}

	printf("%d\n",mdc);
	
	return 0;
}