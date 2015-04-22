#include <stdio.h>

int main(){
	
	char op;
	float a,b;
	int n, i;

	scanf("%d",&n);

	for(i = 0; i < n; i++){
		scanf("%f  %c %f",&a,&op,&b);
		if(op == '+')
			printf("%f\n",a+b);
		else if(op == '-')
			printf("%f\n",a-b);
		else if(op == '*')
			printf("%f\n",a*b);
		else if(op == '/')
			printf("%f\n",a/b);
	}


	return 0;
}