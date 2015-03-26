#include <stdio.h>

int main(){
	int n,num,fat,i,j;

	scanf("%d",&n);

	for(i = 0; i < n;i++){
		scanf("%d",&num);
		fat = 1;
		for(j = 2; j <= num;j++){
			fat = fat*j;
		}
		printf("%d! = %d\n",num,fat);
	}

	return 0;
}