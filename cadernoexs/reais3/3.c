#include <stdio.h>

int main(){
	
	float x, y;
	int n, i;

	printf("Insira n\n");
	scanf("%d",&n);

	for(i = 0; i < n; i++){
		scanf("%f %f",&x,&y);

		if(x*x + y*y <= 1 && x >= 0 && y >= 0)
			printf("O par está na figura!\n");
		else
			printf("O par nao está na figura!\n");
	}


	return 0;
}