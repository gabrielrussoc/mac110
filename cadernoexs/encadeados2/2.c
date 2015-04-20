#include <stdio.h>

int main(){
	
	int n,c1,c2,hip,achei;

	scanf("%d",&n);

	for(hip = 1; hip <= n; hip++){
		
		achei = 0;
		
		for(c1 = 1; c1 < hip && !achei; c1++){
		
			c2 = c1; //evita permutar

			while(c1*c1 + c2*c2 < hip*hip)
				c2++;

			if(c1*c1 + c2*c2 == hip*hip){
				achei = 1;
				printf("%d ",hip);
			}
		}
	}	

	printf("\n");

	return 0;
}