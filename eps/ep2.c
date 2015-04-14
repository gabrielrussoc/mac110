/*	********************************************************************* */
/*	Nome:	Gabriel de Russo e Carmo																																																																																			*/
/*	Numero	USP:	9298041																																																									*/
/*	Exercício-programa	2																																																																																																							*/
/*	********************************************************************* */

#include <stdio.h>
#define SEED 3
#define TRUE 1
#define FALSE 0
#define PEDRA 1
#define TESOURA 2
#define PAPEL 3
#define K 20


int main(){


	/*
	nancy = jogada da maquina
	humano = jogada do humano
	dif = dificuldade
	v,d,e,total = vitorias, derrotas (do humano), empates e total
	a,b,m,x = parametros para o metodo das congruencias lineares
	*/
	int nancy, humano, v, d, e, a, b, total, dif, historico[K], pedra, papel, tesoura, i, j;
	long m = 4294967296, x = SEED;
	a = 22695477;
	b = 1;
	e = v = d = total = 0;

	for (i = 0; i < K; i++){
		historico[i] = 0;
	}

	printf(" ___________________________________________________________ \n");
	printf("| Bem-vindo ao famoso jogo Pedra, Papel e Tesoura!          |\n");
	printf("| As regras são as clássicas que você já deve conhecer:     |\n");
	printf("|                                                           |\n");
	printf("|               Pedra ganha de tesoura                      |\n");
	printf("|               Tesoura ganha de papel                      |\n");
	printf("|               Papel ganha de pedra                        |\n");
	printf("|                                                           |\n");
	printf("| Lembre-se que existe a possibilidade de empate.           |\n");
	printf("| Seu adversário será a máquina Nancy! Divirta-se!          |\n");
	printf("|___________________________________________________________|\n\n");

	printf("Escolha a dificuldade:\n");
	printf("1 - Fácil\n");
	printf("2 - Médio\n");
	printf("3 - Difícil\n");
	scanf("%d",&dif);

	printf("\n");

	if(dif == 1){

		printf("Insira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
		scanf("%d",&humano);

		while(humano){
			
			/*gera a jogada da maquina e printa a correspondencia*/	
			x = (a*x + b)%m;

			if( (float) x/m < 1.0/3){
				nancy = PEDRA;
				printf("(Nancy) Pedra X ");
			}	
			else if( (float) x/m < 2.0/3){
				nancy = TESOURA;
				printf("(Nancy) Tesoura X ");
			}	
			else if( (float) x/m <= 1){
				nancy = PAPEL;
				printf("(Nancy) Papel X ");
			}

			/*printa a jogada correspondente do humano*/
			if(humano == 1){
				printf("Pedra (Voce)\n");
			} else if (humano == 2){
				printf("Tesoura (Voce)\n");
			} else if (humano == 3){
				printf("Papel (Voce)\n");
			}

			/*verifica a rodada*/
			if(nancy == humano){
				printf("Empate!\n");
				e++;
			} else if(humano - nancy == 1 || humano - nancy == -2){
				printf("Nancy ganhou!\n");
				d++;
			} else {
				printf("Voce ganhou!\n");
				v++;
			}

			total++;

			printf("\n");
			printf("Insira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
			scanf("%d",&humano);

		}

	} else if (dif == 2){
		
		
		printf("Insira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
		scanf("%d",&humano);
		historico[0%K] = humano;

		for (i = 1; humano; i++){

			pedra = papel = tesoura = 0;
			
			/*se a jogada anterior for pedra*/
			if (historico[(i-1)%K] == PEDRA){
				for (j = 0; j < K; j++){
					if (historico[j] == PEDRA){
						if (historico[(j+1)%K] == PEDRA){
							pedra++;
						} else if (historico[(j+1)%K] == PAPEL){
							papel++;
						} else if (historico[(j+1)%K] == TESOURA){
							tesoura++;
						}
					}
				}
			} 

			/*se a jogada anterior for tesoura*/
			else if (historico[(i-1)%K] == TESOURA){
				for (j = 0; j < K; j++){
					if (historico[j] == TESOURA){
						if (historico[(j+1)%K] == PEDRA){
							pedra++;
						} else if (historico[(j+1)%K] == PAPEL){
							papel++;
						} else if (historico[(j+1)%K] == TESOURA){
							tesoura++;
						}
					}
				}
			} 

			/*se a jogada anterior for papel*/
			else if (historico[(i-1)%K] == PAPEL){
				for (j = 0; j < K; j++){
					if (historico[j] == PEDRA){
						if (historico[(j+1)%K] == PEDRA){
							pedra++;
						} else if (historico[(j+1)%K] == PAPEL){
							papel++;
						} else if (historico[(j+1)%K] == TESOURA){
							tesoura++;
						}
					}
				} 
			} 

			/*calcula a jogada da maquina com base nos dados levantados*/
			
				x = (a*x + b)%m;

				if( (float) x/m < (float) papel/(papel+tesoura+pedra) ){
					nancy = PEDRA;
				}	
				else if( (float) x/m < (float) pedra/papel){
					nancy = TESOURA;
				}	
				else if( (float) x/m <= 1){
					nancy = PAPEL;
				}

			

			if(nancy == humano){
				printf("Empate!\n");
				e++;
			} else if(humano - nancy == 1 || humano - nancy == -2){
				printf("Nancy ganhou!\n");
				d++;
			} else {
				printf("Voce ganhou!\n");
				v++;
			}

			printf("%d %d %d \n",pedra,papel,tesoura);
			printf("Insira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
			scanf("%d",&humano);
			historico[i%K] = humano;

			


		}












	} else if (dif == 3){
		printf("ainda nao implementei hehehe\n");
	}

	printf(" ______________________ \n");
		printf("|     Quadro Geral     |\n");
		printf("|                      |\n");
		printf("| Nancy: %d vitórias.  |\n",d);
		printf("| Você: %d vitórias.   |\n",v);
		printf("| Empates: %d.         |\n",e);
		printf("| Total: %d.           |\n",total);
		printf("|______________________|\n");	
	
	return 0;
}