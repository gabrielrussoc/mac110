#include <stdio.h>
int main(){
	int n, i, j, cont, num;
	cont = num = 0;
	printf("Insira n, i e j\n");
	scanf("%d %d %d",&n,&i,&j);
	while(cont < n){
		if (num % i == 0 || num % d == 0){
			printf("%d ",num);
			cont++
		}
		num++;
	}
	return 0;
}