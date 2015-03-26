#include <stdio.h>

int main(){
	int n, d, i = 0;
	printf("Insira um numero e um digito\n");
	scanf("%d %d",&n,&d);

	while (n > 0){
		if(n%10 == d){
			i++;
		}
		n = n/10;
	}

	printf("%d se repete %d vezes.\n",d,i);

	return 0;
}