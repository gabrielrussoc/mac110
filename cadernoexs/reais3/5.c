#include <stdio.h>
#include <math.h>

int main(){

	float a,b,c,delta,r1,r2,r1i;

	printf("Insira a, b e c para uma equacao ax2 + bx + c\n");
	scanf("%f %f %f",&a,&b,&c);

	delta = b*b -4*a*c;

	if(delta == 0){
		r1 = (-b + sqrt(delta))/2*a;
		printf("Raiz dupla: %f\n",r1);
	} else if(delta > 0) {
		r1 = (-b + sqrt(delta))/2*a;
		r2 = (-b - sqrt(delta))/2*a;
		printf("Raizes distintas: %f e %f\n",r1,r2);
	} else {
		delta = -delta;
		r1 = (-b/2*a); 
		r1i = sqrt(delta)/2*a;
		printf("Raizes complexas: %f + %fi e %f - %fi\n",r1,r1i,r1,r1i);
	}
	
	return 0;
}