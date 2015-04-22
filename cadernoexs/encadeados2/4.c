#include <stdio.h>

int main(){
	
	int n,num,d,cont,i,soma = 0;

	scanf("%d",&n);

	for(i = 0; i < n; i++){
		cont = 0;
		scanf("%d",&num);
		for(d = 1; d <= num; d++){
			if(num % d == 0)
				cont++;
		}
		if(cont == 2)
			soma += num;
	}

	printf("%d\n",soma);


	return 0;
}