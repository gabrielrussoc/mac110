#include <stdio.h>

int main(){
	
	int n,j,m,cont = 0,i = 1;

	printf("Insira n, j e m\n");
	scanf("%d %d %d",&n,&j,&m);

	//imprimo ele mesmo
	while(cont < n){
		if(i%m == j%m){
			printf("%d ",i);
			cont++;
		}
		i++;
	}
	printf("\n");

	return 0;
}