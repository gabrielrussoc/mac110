#include <stdio.h>

int main(){
	
	float ex = 1,x,eps,termo;
	int k = 1;

	scanf("%f %f",&x,&eps);
	termo = x/1;

	while (termo > eps){
		ex += termo;
		termo = termo*x/(k+1);
		k++;
	}

	printf("%f\n",ex);


	return 0;
}