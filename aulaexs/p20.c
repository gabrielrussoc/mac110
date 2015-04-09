#include <stdio.h>

int main(){
	
	float x, termo, cosseno;
	int k = 1,n, cont = 0;

	cosseno = termo = 1;

	scanf("%f %d",&x,&n);

	while(cont < n){
		termo = -termo*x*x/(k*(k+1));
		cosseno += termo;
		k += 2;
		cont++;

	}

	printf("Cosseno de %f = %f\n",x,cosseno);


	return 0;
}