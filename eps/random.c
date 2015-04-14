/* METODO DAS CONGRUENCIAS LINEARES */

#include <stdio.h>

long random(long x){

	long a,b,m;

	a = 22695477;
	b = 1;
	m = 4294967296;

	x = (x*a + b)%m;

	return x;
}

int main(){
	
	int n, i, x = 3;
	//n = numero de aleatorios

	scanf("%d",&n);
	for(i = 0; i < n; i++){
		x = random(x);
		printf("%f\n", (float) x/4294967296 );
	}





	return 0;
}