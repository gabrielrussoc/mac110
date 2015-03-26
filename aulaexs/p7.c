#include <stdio.h>

int main(){
	int n,i,num,maior;
	
	printf("Entre com n:\n");
	scanf("%d",&n);
	printf("Insira %d numeros",n);
	scanf("%d",&maior);

	for(i = 1; i < n; i++){
		scanf("%d",&num);
		if(num > maior){
			maior = num;
		}
	}

	printf("Maior numero:%d\n",maior);

	return 0;
}