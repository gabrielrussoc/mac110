#include <stdio.h>
int main(){
	int n, nota, i, rec = 0;
	printf("Entre com o numero de alunos \n");
	scanf("%d",&n);
	for (i = 0; i < n;i++){
		scanf("%d",&nota);
		if((nota > 30) && (nota < 50)){
			rec++;
		}
	}
	printf("Recuperacao = %d\n",rec);
	return 0;
}