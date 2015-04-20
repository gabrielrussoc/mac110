#include <stdio.h>

int primo(int n){

	int d,cont = 0;

	for(d = 1; d <= n; d++){
		if(n % d == 0)
			cont++;
	}

	if(cont == 2)
		return 1;
	else
		return 0;
}

int main(){

	int n, cont = 0, soma = 0,i;

	scanf("%d",&n);

	for(i = 1; cont < n; i++){
		if(primo(i)){
			soma += i;
			cont++;
		}	
	}

	printf("%d\n",soma);
	
	return 0;
}