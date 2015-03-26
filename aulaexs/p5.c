#include <stdio.h>

int main(){
	int n, num, somapos, somaneg;
	somapos = 0;
	somaneg = 0;
	
	printf("Entre com n\n");
	scanf("%d",&n);
	printf("Entre com %d numeros:\n",n);

	while(n > 0){
		scanf("%d",&num);
		if(num > 0){
			somapos = somapos + num;
		} else {
			somaneg = somaneg + num;
		}
		n = n - 1;
	}

	printf("Soma dos positivos: %d\n",somapos);
	printf("Soma dos negativos: %d\n",somaneg);
	
	return 0;
}