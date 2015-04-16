/*	********************************************************************* */
/*	Nome:	Gabriel de Russo e Carmo																																																																																			*/
/*	Numero	USP:	9298041																																																									*/
/*	Exercício-programa	2																																																																																																							*/
/*	********************************************************************* */

#include <stdio.h>
#define PEDRA 1
#define TESOURA 2
#define PAPEL 3
#define K 20
#define EMPATE 0
#define VITORIA 1
#define DERROTA 2

long random(long x){

	int a,b;
	long m;

	a = 22695477;
	b = 1;
	m = 4294967296;

	x = (x*a + b)%m;

	return x;

}

int facil(long x){

	int nancy;
	long m;
	m = 4294967296;

	if( (float) x/m < 1.0/3){
		nancy = PEDRA;
	}	
	else if( (float) x/m < 2.0/3){
		nancy = TESOURA;
	}	
	else if( (float) x/m < 1){
		nancy = PAPEL;
	}

	return nancy;

}

int medio(long x, int pedra, int tesoura, int papel, int tot){

	int nancy;
	long m;
	m = 4294967296;

	//chance do cara jogar papel
	if( (float) x/m < (float) papel/tot ){
		nancy = TESOURA;
	}
	//chance do cara jogar tesoura	
	else if( (float) x/m < (float) (tesoura+papel)/tot){
		nancy = PEDRA;
	}
	//chance do cara jogar pedra	
	else if( (float) x/m <= 1){
		nancy = PAPEL;
	}

	return nancy;

}

int verifica(int nancy, int humano){

	int rodada;

	if(nancy == humano){
		rodada = EMPATE;
	} else if(humano - nancy == 1 || humano - nancy == -2){
		rodada = DERROTA;
	} else {
		rodada = VITORIA;
	}

	return rodada;
}

int main(){


	/*
	nancy = jogada da maquina
	humano = jogada do humano
	dif = dificuldade
	v,d,e,total = vitorias, derrotas (do humano), empates e total
	a,b,m,x = parametros para o metodo das congruencias lineares
	*/
	int nancy, humano, v, d, e, a, b, total, dif, historico[K], pedra, papel, tesoura, i, j, tot;
	e = v = d = total = 0;
	long x = 3;

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
			
			x = random(x);
			nancy = facil(x);

			if (verifica(nancy,humano) == EMPATE){
				e++;
			} else if (verifica(nancy,humano) == VITORIA){
				v++;
			} else if (verifica(nancy,humano) == DERROTA){
				d++;
			}
			

			total++;

			printf("\n");
			printf("Insira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
			scanf("%d",&humano);

		}

	} else if (dif == 2){
		
		for (i = 0; humano; i++){

			pedra = papel = tesoura = tot = 0;
			
			/*se a jogada anterior for pedra*/
			if (historico[(i-1)%K] == PEDRA){
				for (j = 0; j < K; j++){
					if (historico[j] == PEDRA){
						tot++;
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
						tot++;
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
					if (historico[j] == PAPEL){
						tot++;
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
			
			x = random(x);
			nancy = medio(x,pedra,tesoura,papel,tot);

			printf("Insira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
			scanf("%d",&humano);
			historico[i%K] = humano;

			if (verifica(nancy,humano) == EMPATE){
				e++;
			} else if (verifica(nancy,humano) == VITORIA){
				v++;
			} else if (verifica(nancy,humano) == DERROTA){
				d++;
			}
			

			
				


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