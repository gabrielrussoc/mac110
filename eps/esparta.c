#include <stdio.h>

int main(){
	int n, m,d,c,l,x,v,i;
	printf("Insira um numero inteiro <= 3000\n");
	scanf("%d",&n);
	m = n/1000;
	n -= (m*1000);
	d = n/500;
	n -= (d*500);
	c = n/100;
	n -= (c*100);
	l = n/50;
	n -= (l*50);
	x = n/10;
	n -= (x*10);
	v = n/5;
	n -= (v*5);
	i = n;

	printf("Em algarimos romanos: ");

	while(m > 0){
		printf("M");
		m--;
	}

	if(d == 1){
		printf("D");
		d--;
	}

	while(c > 0){
		if(c < 4){
			printf("C");
			c--;
		} else {
			printf("CD");
			c = 0;
		}
	}

	if(l == 1){
		printf("L");
		l--;
	}

	while(x > 0){
		if(x < 4){
			printf("X");
			x--;
		} else {
			printf("XL");
			x = 0;
		}
	}

	if(v == 1){
		printf("V");
		v--;
	}

	while(i > 0){
		if(i < 4){
			printf("I");
			i--;
		} else {
			printf("IV");
			i = 0;
		}
	}

	printf("\n");
	
	return 0;
}