#include <stdio.h>
int main(){
	int n,k,aux,elev;
	elev = 1;
	printf("Digite n e k para n^k: \n");
	scanf("%d %d",&n,&k);
	aux = k;
	while(aux >= 1){
		elev = elev*n;
		aux = aux-1;
	}
	printf("%d^%d = %d\n", n, k, elev);
	return 0;
}

/* da p fazer sem a variavel auxiliar, mas nao consigo imprimir k inicial depois */