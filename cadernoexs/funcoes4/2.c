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

	int a,b,seg = 0,aux;

	//item a
	printf("Insira a e b\n");
	scanf("%d %d",&a,&b);

	if(encaixa(a,b))
		printf("%d encaixa em %d\n",b,a);
	else
		printf("%d NAO encaixa em %d\n",b,a);

	//item b
	printf("Insira a e b\n");
	scanf("%d %d",&a,&b);

	if(a > b){
		aux = a;
		while(aux >= b && !seg){
			if(encaixa(aux,b))
				seg = 1;
			aux = aux/10;
		}
		if(seg)
			printf("%d é segmento de %d\n",b,a);
	} else {
		aux = b;
		while(aux >= a && !seg){
			if(encaixa(aux, a))
				seg = 1;
			aux = aux/10;
		}	
		if(seg)
			printf("%d é segmento de %d\n",a,b);
	}

	if(!seg)
		printf("um nao é segmento do outro\n");

	
	return 0;
}