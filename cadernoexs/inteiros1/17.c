#include <stdio.h>
int main(){
	int dec, cont = 1, bin = 0;
	printf("Insira um numero decimal para conversao:\n");
	scanf("%d",&dec);
	while (dec > 0){
		bin = (dec % 2) * cont + bin;
		dec = dec / 2;
		cont = cont * 10;
	}
	printf("Na base binaria:%d \n",bin);
	return 0;
}