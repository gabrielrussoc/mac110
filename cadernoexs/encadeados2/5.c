#include <stdio.h>

int main(){
	
	int m,i,j,k = 1;

	scanf("%d",&m);

	for(i = 1; i <= m; i++){	
		printf("%d*%d*%d = %d",i,i,i,k);
		for(j = 1; j < i; j++)
			printf(" + %d",k+2*j);
		k = k+2*i;
		printf("\n");
	}

	return 0;
}