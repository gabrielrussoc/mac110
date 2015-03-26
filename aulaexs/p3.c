#include <stdio.h>

int main(){
	int n, aux, fat;
	fat = 1;
	printf("Digite o numero desejado:\n");
	scanf("%d",&n);
	aux = n;
	while(aux > 1){
		fat = fat*aux;
		aux = aux -1;
	}
	printf("%d! = %d", n, fat);
	return 0;
}
