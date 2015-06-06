#include <stdio.h>
#define MAX 150

void insereFila(int fila[MAX], int *fim,int val){
	fila[*fim] = val;
	*fim = (*fim + 1) % MAX;
}

void removeFila(int fila[MAX], int *ini){
	fila[*ini] = -1;
	*ini = (*ini + 1) % MAX;
}

int main(){
	
	int fila[MAX];
	int ini, fim;
	ini = fim = 0;

	insereFila(fila,&fim,3);
	insereFila(fila,&fim,4);
	insereFila(fila,&fim,6);
	removeFila(fila,&ini);
	insereFila(fila,&fim,7);
	insereFila(fila,&fim,12);
	insereFila(fila,&fim,5);
	removeFila(fila,&ini);


	for(int i = ini; i < fim; i++)
		printf("%d ",fila[i]);
	printf("\n");



	return 0;
}