/*	********************************************************************* */
/*	Nome:	Gabriel de Russo e Carmo																																																																																			*/
/*	Numero	USP:	9298041																																																									*/
/*	Exercício-programa	1																																																																																																							*/
/*	********************************************************************* */

#include <stdio.h>
#define HUMANO 0
#define COMPUTADOR 1

int main(){
	
	/* n = numero de peças na mesa
	m = numero maximo de peças que podem ser retiradas por jogada
	jog = jogada de ambos
	vez = controla quem joga */
	int n,m,jog,vez;

	/*Apresentacao e consideracoes iniciais para o usuario*/
	printf("\n> Jogo do NIM!\n\n");
	printf("> O jogo é bem simples e será jogado contra o computador.\n");
	printf("> Há N peças na mesa e são retiradas até M peças por jogada.\n");
	printf("> Ganha quem retirar a(s) última(s) peça(s).\n\n");

	/*Leitura dos parametros da partida*/
	printf("> Insira N (peças iniciais) e M (máximo que pode ser retirado):\n");
	printf("> ");
	scanf("%d %d",&n,&m);

	/*Informacoes especificas da partida*/
	printf("\n------------------------------------------\n");
	printf("> %d peças foram colocadas sobre a mesa.\n",n);
	printf("> Não retire mais que %d peças por jogada!\n",m);
	printf("------------------------------------------\n\n");

	/*Decide quem começa, com base na estrategia vencedora */
	if(n % (m+1) == 0){
		vez = HUMANO; 	
		printf("> O computador está feliz! Você começa!\n");
	} else {
		vez = COMPUTADOR;
		printf("> Dessa vez o computador começa!\n");
	}

	/*O jogo continua enquanto houver peças na mesa*/
	while (n > 0){ 

		/*Vez do humano*/
		if(vez == HUMANO){ 
			printf("> Faça sua jogada! Retire até %d peças.\n",m);
			
			/*Escaneia a jogada do humano*/
			printf("> ");
			scanf("%d",&jog);

			/*Retira as peças da mesa*/
			printf("\n> Você retirou %d peça(s).\n",jog);
			n = n - jog; 

			printf("> Peças restantes: %d.\n\n",n);
			printf("------------------------------------------\n\n");
			
			/*Passa a vez*/
			vez = COMPUTADOR; 

		/*Vez da maquina*/
		} else { 
			/*Calcula a jogada da maquina*/
			jog = n % (m+1);

			/*Retira as peças da mesa*/ 
			printf("> O computador retirou %d peça(s).\n",jog);
			n = n - jog;

			printf("> Peças restantes: %d.\n\n",n);
			printf("------------------------------------------\n\n");
			
			/*Passa a vez*/
			vez = HUMANO; 				
		}

	}

	/*Se na vez do humano a mesa estiver vazia, ele perde (if arbitrario)*/
	if(vez == HUMANO)
		printf("> Você perdeu! Mais sorte na próxima!\n\n");
	else
		printf("> Você ganhou! Trapaceiro...\n\n");

	return 0;
}
