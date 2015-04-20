#include <stdio.h>

int main(){
	
	int n,seg = 1,atual,anterior,i,maiorSeg = 1;

	printf("Insira n\n");
	scanf("%d",&n);
	printf("Insira %d numeros:\n",n);
	scanf("%d",&anterior);

	for(i = 1; i < n; i++){
		scanf("%d",&atual);
		if(atual > anterior){
			seg++;
			if(seg > maiorSeg)
				maiorSeg = seg;
		}	

		else
			seg = 1;
	}

	printf("%d\n",maiorSeg);

	return 0;
}