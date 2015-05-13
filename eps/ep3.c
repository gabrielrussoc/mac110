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

	k = 11;
	
	printf("Voce deseja: \n");
	printf("1 - Encriptar\n");
	printf("2 - Decriptar\n");
	scanf("%d",&aux);

	if(aux == 1){

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

		printf("%s",ciphertext);
	}
	else{

		scanf("%s",ciphertext);

		for(i = 0; ciphertext[i] != '\0'; i++){
			if(ciphertext[i] == '.')
				ciphercode[i] = 27;
			else if(ciphertext[i] == '_')
				ciphercode[i] = 0;
			else
				ciphercode[i] = ciphertext[i] - 'A' + 1;
		}

		n = i;

		for(i = 0; i < n; i++)
			plaincode[(k * i) % n] = mod28(ciphercode[i] + i);

		for(i = 0; i < n; i++){
			if(plaincode[i] == 27)
				plaintext[i] = '.';
			else if(ciphercode[i] == 0)
				plaintext[i] = '_';
			else
				plaintext[i] = plaincode[i] + 'A' - 1;

		}

		printf("%s",plaintext);

	}

	printf("\n");

	return 0;
}