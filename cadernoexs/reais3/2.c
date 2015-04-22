#include <stdio.h>

int main(){
	
	int i, n;
	float harm = 0;

	printf("Insira n\n");
	scanf("%d",&n);

	for(i = 0; i < n; i++){
		harm += (float) 1/(i+1);
	}

	printf("Harmonico: %f\n",harm);

	return 0;
}