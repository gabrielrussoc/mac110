/* METODO DAS CONGRUENCIAS LINEARES */

#include <stdio.h>

int main(){
	
	int a,b,m,x[100000],n, i;
	a = 22695477;
	b = 1;
	m = 4294967295; 

	scanf("%d %d",&x[0],&n);

	for(i = 0; i < n; i++){

		x[i+1] = (a*x[i] + b)%m;

		printf("%d\n",x[i+1]);

	}






	return 0;
}