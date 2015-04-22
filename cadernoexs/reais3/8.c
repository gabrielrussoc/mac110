#include <stdio.h>

int main(){

	float mediaSala, mediaAluno, n1, n2, n3;
	int n, i, aprov, reprov;
	aprov = reprov = mediaSala = 0;

	printf("Insira o numero de alunos\n");
	scanf("%d",&n);

	for(i = 0; i < n; i++){
		scanf("%f %f %f",&n1,&n2,&n3);
		mediaAluno = (n1 + n2 + n3)/3;
		if(mediaAluno >= 5)
			aprov++;
		else
			reprov++;
		printf("Media Aluno %d = %f\n",i+1,mediaAluno);
		mediaSala += mediaAluno;
	}

	mediaSala = mediaSala/n;

	printf("Media da sala = %f\nAprovados: %d\nReprovados: %d\n",mediaSala,aprov,reprov);
	
	return 0;
}