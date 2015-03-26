#include <stdio.h>

int main(){
	int n,k,aux,nk;
	nk = 1;
	printf("Digite n e k:\n");
	scanf("%d %d",&n,&k);
	aux = k;
	while(aux >= 1){
		nk = nk*n;
		aux = aux - 1;	
	}
	printf("%d^%d = %d",n,k,nk);
	return 0;
}
