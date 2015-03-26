#include <stdio.h>

int main(){
	int i, n, num, par = 0, impar = 0;
	printf("Entre com n: \n");
	scanf("%d",&n);
	printf("Entre com %d numeros:\n",n);

	for (i = 0; i < n; i++){
		scanf("%d",&num);
		if(num % 2 == 0){
			par++;
		} else {
			impar++;
		}
	}
	printf("Numero de pares:%d\n",par);
	printf("Numero de impares:%d\n",impar);
	
	return 0;
}