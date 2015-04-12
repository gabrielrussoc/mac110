/* METODO DAS CONGRUENCIAS LINEARES */

#include <stdio.h>

int main(){
	
	int a,b,x,n = 100, i,pedra = 0, papel = 0, tesoura = 0;
	a = 22695477;
	b = 1;
	unsigned int m = 2147483648;

	scanf("%d",&x);
	for(i = 0; i < n; i++){

		x = (a*x + b)%m;

		if( (float) x/m < (float) 1/3)
			pedra++;
		else if( (float) x/m < (float) 2/3)
			tesoura++;
		else
			papel++;

	}

	printf("%d %d %d\n",pedra,tesoura,papel);






	return 0;
}