#include <stdio.h>

int main(){

	float x, cosseno, termo;
	int i = 0, n, k = 1;

	printf("Insira um real e N natural\n");
	scanf("%f %d",&x,&n);

	cosseno = termo = 1;

	while(i < n){
		termo = -termo*x*x/(k*(k+1));
		cosseno += termo;
		k += 2;
		i++;
	}	

	

	printf("Cosseno de %f: %f\n",x,cosseno);


	return 0;
}