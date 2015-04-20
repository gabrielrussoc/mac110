#include <stdio.h>

int contaDigito(int n, int d){
		
	int vezes = 0;	

	while(n){
		if(n%10 == d)
			vezes++;
		n = n/10;
	}

	return vezes;
}


int main(){

	int n, d, a ,b,permut = 1, aux;

	//item a
	printf("Insira um numero e um digito\n");
	scanf("%d %d",&n,&d);
	printf("O digito %d aparece %d vezes\n",d,contaDigito(n,d));
	
	//item b
	printf("Insira 2 numeros\n");
	scanf("%d %d",&a,&b);
	aux = b;
	while(aux && permut){

		if(contaDigito(a,aux%10) != contaDigito(b,aux%10))
			permut = 0;
		aux = aux/10;
	}


	if(permut)
		printf("%d é pemutacao de %d\n",a,b);
	else
		printf("%d NAO é pemutacao de %d\n",a,b);

	return 0;
}