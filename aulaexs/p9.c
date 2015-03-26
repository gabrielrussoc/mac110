#include <stdio.h>
int main(){
	int n, numAnt, numAtual, i, cresc = 1;
	printf("Entre com n\n");
	scanf("%d",&n);
	printf("Entre com %d numeros:\n",n);
	scanf("%d",&numAnt);
	for(i = 1; i < n & cresc == 1; i++){
		scanf("%d",&numAtual);
		if(numAtual < numAnt){
			cresc = 0;
		}
		numAnt = numAtual;
	}
	if(cresc == 1){
		printf("A sequencia e crescente\n");
	} else {
		printf("A sequencia nao e crescente\n");
	}
	return 0;
}