#include <stdio.h>
#define MAX 1200


void bubblesort(int v[MAX], int n){

	int i, j,aux;

	for(i = 0; i < n; i++){
		for(j = 0; j < n-1; j++){
			if(v[j] > v[j+1])
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux; 
		}
	}

}

void selectionsort(int v[MAX], int n){


	int i, j, aux, min;

	for(i = 0; i < n - 1; i++){
		min = i;
		for(j = i + 1; j < n; j++){
			if(v[j] < v[min])
				min = j;
		}
		aux = v[i];
		v[i] = v[min];
		v[min] = aux;
	}


}


int main(){
	
	int v[MAX], i, n;


	printf("Insira N\n");
	scanf("%d",&n);

	for(i = 0; i < n; i++)
		scanf("%d",&v[i]);

	selectionsort(v,n);

	for(i = 0; i < n; i++)
		printf("%d ",v[i]);
	printf("\n");

	return 0;
}