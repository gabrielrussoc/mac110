#include <stdio.h>
int main(){
	int n, aux = 1;
	printf("Digite um numero para verificacao:\n");
	scanf("%d",&n);
	while((aux * (aux + 1) * (aux + 2)) < n){
		aux++;
	}
	if((aux * (aux + 1) * (aux + 2)) == n){
		printf("%d eh triangular\n",n);
	} else {
		printf("%d nao eh triangular\n",n);
	}
	return 0;
}