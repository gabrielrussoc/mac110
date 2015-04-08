#include <stdio.h>

int main(){
	
	float x, eps = 0.001, arc, termo;
	int k = 1;

	scanf("%f",&x);
	arc = termo = x;

	while (termo < -eps || termo > eps){
		termo = -termo*x*x*k/(k+2);
		arc += termo;
		k += 2;
	}

	printf("Arctan de %f %f\n",x,arc);

	return 0;
}