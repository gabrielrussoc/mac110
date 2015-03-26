#include <stdio.h>
int main(){
	int a, b, c;
	printf("Digite os lados do triangulo: \n");
	scanf("%d %d %d",&a,&b,&c);
	if (a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b){
		printf("O triangulo eh retangulo!\n");
	} else{
		printf("O triangulo nao eh retangulo ou nao existe!\n");
	}
	return 0;
}