#include <stdio.h>

int main(){
	
	float x, y;
	int n, i, cont = 0;

	printf("Insira n\n");
	scanf("%d",&n);

	for(i = 0; i < n; i++){
		scanf("%f %f",&x,&y);

		if(x <= 0 && y <= 0 && y + x*x + 2*x -3 <= 0){
			printf("O par está no conjunto!\n");
			cont++;
		} else if(x >= 0 && y + x*x -2*x -3 <= 0){
			printf("O par está no conjunto!\n");
			cont++;
		} else
			printf("O par nao está no conjunto.\n");

	}

	printf("Total de pares lidos no conjunto: %d\n",cont);


	return 0;
}