#include <stdio.h>
int main(){
	int valor, maiorValor = 0, dia;
	printf("Insira o numero de discos vendidos nos dias de marco:\n");
	for(int i = 1; i <= 31; i++){
		printf("Dia %d: \n",i);
		scanf("%d",&valor);
		if(valor > maiorValor){
			maiorValor = valor;
			dia = i;
		}
	}
	printf("O dia %d foi o mais produtivo com %d discos vendidos. \n", dia, maiorValor);
	return 0;
}