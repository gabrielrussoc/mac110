#include <stdio.h>

int main(){
	
	int i, n;
	float h = 0;

	printf("Insira n\n");
	scanf("%d",&n);

	for(i = 0; i < n; i++){
		h += (float) 1/(i+1);
	}

	printf("Harmonico de %d eh %f\n",n,h);

	return 0;
}