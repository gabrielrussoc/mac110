#include <stdio.h>

int main(){
	
	int n,seg = 1,atual,anterior,i;

	printf("Insira n\n");
	scanf("%d",&n);
	printf("Insira %d numeros:\n",n);
	scanf("%d",&anterior);

	for(i = 1; i < n; i++){
		scanf("%d",&atual);
		if(atual != anterior)
			seg++;
		anterior = atual;
	}

	printf("%d\n",seg);

	return 0;
}