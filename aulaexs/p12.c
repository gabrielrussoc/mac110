#include <stdio.h>

int main(){
	
	int n,d,mult;

	scanf("%d",&n);

	for(d = 2; d <= n; d++){
		mult = 0;
		while(n%d == 0){
			n = n/d;
			mult++;
		}

		if(mult > 0){
			printf("Fator %d multiplicidade %d\n",d,mult);
		}

	}

	return 0;
}