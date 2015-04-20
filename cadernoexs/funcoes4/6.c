#include <stdio.h>

float arctan(float x){

	float eps = 0.0001, termo,result,k = 1;
	termo = result = x;

	while(termo > eps || termo < -eps){
		k += 2;
		termo = -termo*x*x*(k-2)/k;
		result += termo;
	}

	return result;

}

float angulo(float x, float y){

	float angulo;

	if(y < x)
		angulo = 180*arctan(y/x)/3.14;
	else
		angulo = 180/3.14*(3.14/2 - arctan(x/y));

	return angulo;

}


int main(){
	
	int n,i;
	float x,y,atual,menor,x1,y1;

	scanf("%d",&n);

	scanf("%f %f",&x,&y);
	menor = angulo(x,y);
	x1 = x;
	y1 = y;

	for(i = 1; i < n; i++){
		scanf("%f %f",&x,&y);
		atual = angulo(x,y);
		if(atual < menor){
			menor = atual;
			x1 = x;
			y1 = y;
		}	

	}

	printf("O par (%f,%f) forma o menor angulo (%f).\n",x1,y1,menor);

	return 0;
}