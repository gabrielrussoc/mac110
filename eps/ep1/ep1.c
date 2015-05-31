/*	**************************************************************************	*/
/*	Nome:	Gabriel de Russo e Carmo																																																																																			*/
/*	Numero	USP:	9298041																																																									*/
/*	Exercício-programa	1																																																																																																							*/
/*	**************************************************************************	*/

#include <stdio.h>
#define HUMANO 0
#define COMPUTADOR 1

int main(){
	
	int n,m,jog,vez;
	/* n = numero de peças na mesa
	m = numero maximo de peças que podem ser retiradas por jogada
	jog = jogada de ambos
	vez = controla quem joga */

	/*Apresentacao e consideracoes iniciais para o usuario*/
	printf("\nJogo do NIM!\n\n");
	printf("O jogo é bem simples e será jogado contra o computador.\n");
	printf("Existem N peças na mesa e cada jogador retira até M peças por jogada.\n");
	printf("Ganha quem retirar a(s) última(s) peça(s).\n\n");

	/*Leitura dos parametros da partida*/
	printf("Insira N (peças iniciais) e M (máximo a ser retirado por jogada):\n");
	scanf("%d %d",&n,&m);

	/*Mais informacoes para o usuario*/
	printf("\n----------------------------------------\n");
	printf("%d peças foram colocadas sobre a mesa.\n",n);
	printf("Não retire mais que %d peças por jogada!\n",m);
	printf("----------------------------------------\n\n");

	/*Decide quem começa usando a estrategia vencedora*/
	if(n%(m+1) == 0){
		vez = HUMANO; /*Vez do humano*/	
		printf("O computador está feliz! Você começa!\n");
	} else {
		vez = COMPUTADOR; /*Vez da maquina*/
		printf("Dessa vez o computador começa!\n");
	}


	while (n > 0){ /*O jogo continua enquanto houver peças na mesa*/

		if(vez == HUMANO){ /*Vez do humano*/
			printf("Faça sua jogada! Retire até %d peças.\n",m);
			scanf("%d",&jog); /*Escaneia a jogada do humano*/
			printf("\nVocê retirou %d peça(s).\n",jog);
			n -= jog; /*Retira as peças da mesa*/
			printf("Peças restantes: %d.\n\n",n);
			vez = COMPUTADOR; /*Passa a vez*/

		} else { /*Vez da maquina*/
			jog = n%(m+1); /*Calcula a jogada da maquina, com base na estrategia vencedora*/
			printf("O computador retirou %d peça(s).\n",jog);
			n -= jog; /*Retira as peças da mesa*/
			printf("Peças restantes: %d.\n\n",n);
			printf("----------------------------------------\n\n");
			vez = HUMANO; /*Passa a vez*/				
		}

	}

	printf("Você perdeu! Mais sorte na próxima!\n\n"); /*Dispensa condições ja que a maquina sempre ganha*/
 	
	return 0;
}
