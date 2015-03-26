#include <stdio.h>
int main(){
	int n1, n2, n3, cont;
	n1 = 1; n2 = 1;
	printf("Digite um numero\n");
	scanf("%d",&cont);
	printf("O %d numero da sequencia de Fibonacci eh: ",cont);
	if (cont < 3){
		printf("1\n");
	} else {
		while (cont >= 3){
			n3 = n1 + n2;
			n1 = n2;
			n2 = n3;
			cont--;
		}
		printf("%d\n",n3);
	}
	return 0;
}