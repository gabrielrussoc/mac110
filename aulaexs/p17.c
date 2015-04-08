#include <stdio.h>

int main(){
	float x, ro, rn, eps, tmp;
	int ok = 1;

	printf("Insira x e epsilon\n");
	scanf("%f %f",&x,&eps);

	ro = x;


	while(ok){
		rn = 0.5*(ro + x/ro);
		tmp = rn - ro;

		if(tmp < 0)
			tmp = -tmp;

		if(tmp < eps)
			ok = 0;

		ro = rn;
	}

	printf("Raiz de %f = %f\n",x,rn);

	return 0;
}