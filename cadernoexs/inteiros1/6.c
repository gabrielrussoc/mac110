#include <stdio.h>
int main(){
	int maior = 0,menor = 100,nota, alunos;
	printf("Insira o numero de alunos: \n");
	scanf("%d",&alunos);
	for (int cont = 1; cont <= alunos; cont++){
		printf("Nota do aluno %d: \n", cont);
		scanf("%d", &nota);
		if(nota > maior){
			maior = nota;
		} 
		if(nota < menor) {
			menor = nota;
		} 
	}
	printf("Maior nota: %d\nMenor nota: %d \n",maior, menor);
	return 0;
}