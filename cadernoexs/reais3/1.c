#include <stdio.h>

int main(){
	
	float capital, taxa, juros;
	int i;

	printf("Insira o capital e a taxa mensal\n");
	scanf("%f %f",&capital,&taxa);

	//considerei simples (j = cit)

	for(i = 1; i <= 12; i++){

		juros = capital*taxa*i; 
		printf("Mes %d: %.2f complexos\n",i,juros+capital);


	}

	return 0;
}