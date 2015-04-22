#include <stdio.h>

int main(){
	
	int qtd = 0;
	float x, y, uaua, ny;

	printf("Insira a pop de Uaua e Nova York\n");
	scanf("%f %f",&uaua,&ny);

	printf("Insira as respectivas taxas de crescimento populacional\n");
	scanf("%f %f",&x,&y);

	if(x > y && uaua < ny){
		while(uaua <= ny){
			uaua = x*uaua;
			ny = y*ny;
			qtd++;
		}
		printf("Uaua passará Nova York em %d\n anos",qtd);
	} else if(y > x && ny < uaua){
		while(ny <= uaua){
			uaua = x*uaua;
			ny = y*ny;
			qtd++;
		}
		printf("Nova York passará Uauá em %d anos\n",qtd);
	} else
		printf("A menor nunca passará a maior\n");



	return 0;
}