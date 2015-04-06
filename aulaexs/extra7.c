#include <stdio.h>

int main(){
	int n,soma = 0;

	scanf("%d",&n);

	while(n > 9){
		
		while (n > 0){
			soma += n%10;
			n = n/10;
		}

		n = soma;
		soma = 0;	

	}

	printf("%d\n",n);


	return 0;
}