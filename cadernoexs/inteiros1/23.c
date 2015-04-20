#include <stdio.h>

int main(){
	
	int n, contrario = 0, aux;

	printf("Insira um numero\n");
	scanf("%d",&n);

	aux = n;

	while(aux){
		contrario = contrario * 10;
		contrario = contrario + aux%10;
		aux = aux/10;
	}

	if(n == contrario)
		printf("%d é palíndrome\n",n);
	else
		printf("%d não é palíndrome\n",n);

	return 0;
}