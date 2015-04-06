#include <stdio.h>

int main(){
		
	int n, i;
	float nota,media;

	printf("Insira n\n");
	scanf("%d",&n);
	printf("Insira %d notas\n",n);

	for(i = 0; i < n; i++){

		scanf("%f",&nota);
		media += nota;

	}

	media = media/n;

	printf("Media: %f\n",media);


	return 0;
}