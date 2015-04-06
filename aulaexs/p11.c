/*Dado um inteiro n, n>o, verificar se n eh primo*/

#include <stdio.h>

int main(){
	
	int n,cont = 0,d;

	printf("Insira n: \n");
	scanf("%d",&n);

	for(d = 1; d <= n; d++){

		if(n%d == 0){
			cont++;
		}

	}

	if(cont == 2)
		printf("%d eh primo\n",n);
	else
		printf("%d nao eh primo\n",n);


	return 0;
}