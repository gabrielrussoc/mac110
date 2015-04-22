#include <stdio.h>

int main(){
	
	int m,n,x,y,max = 0,xm,ym;

	scanf("%d %d",&m,&n);

	for(x = 0; x <= m; x++){
		for(y = 0; y <= n; y++){
			if(x*y - x*x + y > max){
				max = x*y - x*x + y;
				xm = x;
				ym = y;
			}	
		}
	}

	printf("Valor maximo: %d, obtido pelo par (%d,%d)\n",max,xm,ym);

	return 0;
}