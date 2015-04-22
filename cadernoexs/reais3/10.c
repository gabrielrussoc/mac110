#include <stdio.h>

int main(){
	
	int i, n;
	float soma = 0;

	scanf("%d",&n);

	for(i = 0; i < n; i++){
		soma += (float) (i+1)/(n-i);
	}

	printf("%f\n",soma);

	return 0;
}