#include <stdio.h>
int main(){
	int n, aux, primo = 1;
	printf("Digite o numero a ser checado:\n");
	scanf("%d",&n);
	aux = n - 1;
	while(aux >= 2 && primo == 1){
		if(n%aux == 0){
			primo = 0;
		} else {
			aux = aux - 1;
		}
	}
	if(primo == 1){
		printf("%d eh primo\n", n);
	} else {
		printf("%d nao eh primo\n", n);
	}
	return 0;
}