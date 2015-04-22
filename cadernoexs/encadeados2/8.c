#include <stdio.h>

int main(){
	
	int paridade,k,kaux,alternante,n,num,i;

	scanf("%d",&n);

	scanf("%d",&num);
	paridade = num%2;
	i = k = 1;

	while(i < n && num % 2 == paridade){
		scanf("%d",&num);
		i++;
		if(num % 2 == paridade)
			k++;
	}

	alternante = 1;
	while(i < n){
		paridade = (paridade + 1)%2;

		kaux = 1;

		while(i < n && num % 2 == paridade){
			scanf("%d",&num);
			i++;
			if(num % 2 == paridade)
				kaux++;
		}

		if (kaux != k)
			alternante = 0;
	}

	if(num % 2 != paridade && k != 1)
		alternante = 0;

	if(alternante)
		printf("A sequencia e %d-alterante\n",k);
	else
		printf("A sequencia nao e alternante\n");

	return 0;
}