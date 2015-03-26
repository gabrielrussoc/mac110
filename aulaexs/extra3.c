#include <stdio.h>
int main(){
	int n, d1, d2, adj = 0;
	printf("Entre com um numero");
	scanf("%d",&n);
	d1 = n%10;
	n = n/10;
	while (n > 0){
		d2 = n%10;
		if (d1 == d2){
			adj = 1;
		}
		d1 = d2;
		n = n/10;
	}
	if(adj == 1){
		printf("O numero contem 2 digitos adjacentes\n");
	} else {
		printf("O numero nao contem 2 digitos adjacentes\n");
	}
	return 0;
}