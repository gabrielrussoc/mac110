#include <stdio.h>

int main(){
	
	int p,q,sub = 0,aux;

	printf("Insira p e q, onde p <= q\n");
	scanf("%d %d",&p,&q);

	aux = q;

	while(aux && !sub){
		if(p == aux%100)
			sub = 1;
		aux = aux/10;
	}

	if(sub)
		printf("%d é subnumero de %d\n",p,q);
	else
		printf("%d nao é subnumero de %d\n",p,q);

	return 0;
}