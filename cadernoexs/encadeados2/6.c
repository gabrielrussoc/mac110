#include <stdio.h>

int main(){
			
	int num, d, mult;

	scanf("%d",&num);

	for(d = 2; d <= num; d++){
		mult = 0;
		while(num % d == 0){
			mult++;
			num = num/d;
		}
		if(mult)
			printf("Fator %d, multiplicidade %d\n",d,mult);
	}

	return 0;
}