#include <stdio.h>

int encaixa(int a, int b){

	int cont = 1,aux;
	aux = b;

	while(aux){
		cont = cont*10;
		aux = aux/10;
	}

	if(b == a%cont)
		return 1;
	else
		return 0;
}

int main(){

	int a,b,seg = 0,aux,maior,menor;

	/*item a
	printf("Insira a e b\n");
	scanf("%d %d",&a,&b);

	if(encaixa(a,b))
		printf("%d encaixa em %d\n",b,a);
	else
		printf("%d NAO encaixa em %d\n",b,a);*/

	//item b
	printf("Insira a e b\n");
	scanf("%d %d",&a,&b);

	if(a > b){
		maior = a;
		menor = b;
	} else {
		maior = b;
		menor = a;
	}

	aux = maior;
	while(aux && !seg){
		if(encaixa(aux,menor))
			seg = 1;
		aux = aux/10;
	}

	if(seg)
		printf("%d eh segmento de %d\n",menor,maior);
	else
		printf("um nao eh segmento do outro\n");

	return 0;
}