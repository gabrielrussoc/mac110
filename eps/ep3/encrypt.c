#include <stdio.h>

int mod28(int a){
	int res;
	if(a%28 >= 0)
		res = a % 28;
	else
		res = a % 28 + 28;

	return res;
}

int main(){

	int ciphercode[100], plaincode[100];
	char ciphertext[100], plaintext[100];
	
	int k,i,n,aux;

	printf("Insira K\n");
	scanf("%d",&k);
	
	printf("Insira a mensagem\n");

		scanf("%s",plaintext);

		for(i = 0; plaintext[i] != '\0'; i++){
			if(plaintext[i] == '.')
				plaincode[i] = 27;
			else if(plaintext[i] == '_')
				plaincode[i] = 0;
			else
				plaincode[i] = plaintext[i] - 'A' + 1;
		}

		n = i;

		for(i = 0; i < n; i++)
			ciphercode[i] = mod28(plaincode[(k*i)%n] - i);

		for(i = 0; i < n; i++){
			if(ciphercode[i] == 27)
				ciphertext[i] = '.';
			else if(ciphercode[i] == 0)
				ciphertext[i] = '_';
			else
				ciphertext[i] = ciphercode[i] + 'A' - 1;

		}

		printf("%s\n",ciphertext);

	return 0;
}