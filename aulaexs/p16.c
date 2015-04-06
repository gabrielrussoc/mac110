#include <stdio.h>

int main(){
	
	float x,y;
	int i, n;

	printf("Insira n\n");
	scanf("%d",&n);
	printf("Insira %d coordenadas\n",n);

	for(i = 0; i < n; i++){
		scanf("%f %f",&x,&y);
		if(x*x + y*y <= 1 && x >= 0 && y >= 0)
			printf("(%f,%f) faz parte da figura\n",x,y);
		else
			printf("(%f,%f) NAO faz parte da figura\n",x,y);
	}


	return 0;
}