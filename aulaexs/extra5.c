#include <stdio.h>

int main(){
	
	float soma = 0;
	int n,i;

	scanf("%d",&n);

	for(i = 0; i < n; i++){
		soma += (float) (i+1)/(n-i);
	}

	printf("%f\n",soma);

	return 0;
}