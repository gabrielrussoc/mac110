#include <stdio.h>

int main(){
	int n, quadrado;
	printf("Insira os numeros a serem elevados ao quadrado seguidos por 0:\n");
	scanf("%d",&n);
	while(n != 0){
		quadrado = n*n;
		printf("%d^2 = %d\n",n,quadrado);
		scanf("%d",&n);
	}
	return 0;
}