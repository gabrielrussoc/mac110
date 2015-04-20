#include <stdio.h>

int main(){
	
	int n,i,soma,termo;

	printf("Insira n\n");
	scanf("%d",&n);
	printf("Insira n sequencias, cada qual terminada por 0\n");

	for(i = 0; i < n; i++){
		soma = 0;

		scanf("%d",&termo);
		while(termo){
			if(termo % 2 == 0)
				soma += termo;
			scanf("%d",&termo);
		}

		printf("Soma dos pares da sequencia: %d\n",soma);


	}

	return 0;
}