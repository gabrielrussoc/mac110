#include <stdio.h>

int main(){

	float x, eps, seno, termo;
	int k = 2;

	scanf("%f %f",&x,&eps);

	seno = termo = x;	

	while (termo > eps){
		termo = -termo*x*x/(k*(k+1));
		seno += termo;
		k += 2;
	}

	printf("%f\n", seno);


	return 0;
}