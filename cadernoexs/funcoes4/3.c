#include <stdio.h>

int bloco(int n){

	int i,par,impar,num;
	par = impar = 0;

	for(i = 0; i < n; i++){
		scanf("%d",&num);
		if(num % 2 == 0)
			par++;
		else
			impar++;
	}

	if(par && !impar)
		return 0;
	else if(impar && !par)
		return 1;
	else
		return -1;

}

int main(){

	int n,i,soma = 1,pir = 1,ant,atual,cont;

	scanf("%d",&n);
	ant = bloco(1);

	cont = 2;

	while(soma < n){
		atual = bloco(cont);
		if(atual == ant || ant == -1)
			pir = 0;
		soma += cont;
		cont++;
	}

	if(pir && soma == n)
		printf("A sequencia é piramidal %d-alternante\n",cont-1);
	else
		printf("A sequencia nao é piramidal alternante\n");


	
	return 0;
}