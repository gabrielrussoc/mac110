#include <stdio.h>
int main(){
	int n, k;
	k = 1;
	printf("Digite um numero:\n");
	scanf("%d",&n);
	while(n>=1){
		printf("%d ",k);
		k = k + 2;
		n = n - 1;
	}
	printf("\n");
	return 0;
}

/*
#include <stdio.h>
int main(){
	int n, k, aux;
	k = 0;
	printf("Digite um numero:\n");
	scanf("%d",&n);
	while(n>0){
		aux = 2*k+1;
		printf("%d ",aux);
		k = k+1;
		n = n-1;
	}
	printf("\n");
	return 0;
}
*/