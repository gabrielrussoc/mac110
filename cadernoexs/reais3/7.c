#include <stdio.h>

int main(){

	float seno, termo, k = 2, x, eps = 0.0001;

	printf("Insira um real x\n");
	scanf("%f",&x);

	seno = termo = x;

	while(termo > eps || termo < -eps){
		termo = -termo*x*x/(k*(k+1));
		seno += termo;
		k += 2;
	}

	printf("Seno = %f\n",seno);
	
	return 0;
}