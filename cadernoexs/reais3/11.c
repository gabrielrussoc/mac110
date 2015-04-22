#include <stdio.h>

int main(){
	
	int i;
	float soma1, soma2, soma3neg, soma3pos, soma4neg, soma4pos;
	soma1 = soma2 = soma3neg = soma3pos = soma4neg = soma4pos = 0.0;

	for(i = 1; i < 10000; i += 2){

		/* direita para esquerda */
		soma1 += 1.0/(10001 - i) - 1.0/(10001 - (i + 1)) ;

		/* esquerda para direita */
		soma2 += (1.0/i) - (1.0/(i+1));

		/*separado esquerda direita*/
		soma3pos += 1.0/i;
		soma3neg += -(1.0/(i+1));

		/*separado direita esquerda*/
		soma4pos += 1.0/(10001 - i);
		soma4neg += - 1.0/(10001 - (i + 1)); 

	}

	printf("Dir - Esq: %f\n",soma1);
	printf("Esq - Dir: %f\n",soma2);
	printf("Esq - Dir - Pos Neg: %f %f\n",soma3pos,soma3neg);
	printf("Dir - Esq - Pos Neg: %f %f\n",soma4pos,soma4neg);

	return 0;
}