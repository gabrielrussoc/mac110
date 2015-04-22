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

int vitHumano, vitNancy, empates, partidas, historico[K];

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

	if( (float) x/m < 1.0/3 ){
		nancy = PEDRA;
	}	
	else if( (float) x/m < 2.0/3 ){
		nancy = TESOURA;
	}	
	else if( (float) x/m < 1 ){
		nancy = PAPEL;
	}

	return nancy;

}

int medio(long x, int i){

	int j, jogNancy, pedra, papel, tesoura, tot;
	long m;
	m = 4294967296;
	pedra = papel = tesoura = tot = 0;

	/* se a anterior for pedra, eu procuro
	todas as vezes que ele jogou pedra e guardo a
	seguinte*/
	if(historico[(i-1)%K] == PEDRA){
		for(j = 0; j < K; j++){
			if(historico[j] == PEDRA){
				tot++;
				if(historico[(j+1)%K] == PEDRA)
					pedra++;
				else if(historico[(j+1)%K] == PAPEL)
					papel++;
				else if(historico[(j+1)%K] == TESOURA)
					tesoura++;
			}
		}
	} 

	/*processo análogo no caso da ultima ser tesoura*/
	else if(historico[(i-1)%K] == TESOURA){
		for(j = 0; j < K; j++){
			if(historico[j] == TESOURA){
				tot++;
				if(historico[(j+1)%K] == PEDRA)
					pedra++;
				else if(historico[(j+1)%K] == PAPEL)
					papel++;
				else if(historico[(j+1)%K] == TESOURA)
					tesoura++;
			}
		}
	} 

	/* .. ultima papel */
	else if(historico[(i-1)%K] == PAPEL){
		for(j = 0; j < K; j++){
			if(historico[j] == PAPEL){
				tot++;
				if(historico[(j+1)%K] == PEDRA)
					pedra++;
				else if(historico[(j+1)%K] == PAPEL)
					papel++;
				else if(historico[(j+1)%K] == TESOURA)
					tesoura++;
			}
		}
	} 

	/* chance do cara jogar papel */
	if( (float) x/m < (float) papel/tot )
		jogNancy = TESOURA;
	/* chance do cara jogar tesoura */
	else if( (float) x/m < (float) (tesoura+papel)/tot )
		jogNancy = PEDRA;
	/* chance do cara jogar pedra */	
	else if( (float) x/m <= 1 )
		jogNancy = PAPEL;

	return jogNancy;

}

void verifica(int nancy, int humano){

	if(nancy == PEDRA){
		printf("(Nancy) Pedra X");
	} else if (nancy == TESOURA){
		printf("(Nancy) Tesoura X");
	} else if (nancy == PAPEL){
		printf("(Nancy) Papel X");
	}


	if(humano == PEDRA){
		printf(" Pedra (Voce)\n");
	} else if(humano == TESOURA){
		printf(" Tesoura (Voce)\n");
	} else if(humano == PAPEL){
		printf(" Papel (Voce)\n");
	}

	if(nancy == humano){
		printf("Empate!\n");
		empates++;
	} else if(humano - nancy == 1 || humano - nancy == -2){
		printf("Nancy ganhou!\n");
		vitNancy++;
	} else {
		printf("Voce ganhou!\n");
		vitHumano++;
	}

	partidas++;

}

int main(){

	/*
	jogNancy, jogHumano = jogadas
	dif = dificuldade
	vitHumano, vitNancy, empates, partidas = resultados gerais
	x = seed do random
	historico[] = historico das jogadas
	pedra,papel,tesoura,tot = contadores do modo medio
	*/

	int jogNancy, jogHumano, i, dif;

	vitHumano = vitNancy = empates = partidas = 0;
	
	long x = 3;

	printf("Escolha a dificuldade:\n");
	printf("1 - Fácil\n");
	printf("2 - Médio\n");
	printf("3 - Difícil\n");
	scanf("%d",&dif);

	printf("\n");

	if(dif == 1){

		printf("Insira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
		scanf("%d",&jogHumano);

		while(jogHumano){
			
			x = random(x);
			jogNancy = facil(x);
			verifica(jogNancy,jogHumano);

			printf("\nInsira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
			scanf("%d",&jogHumano);

		}

	} else if(dif == 2){

		/*jogo aleatório nas K primeiras jogadas */
		printf("Insira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
		scanf("%d",&jogHumano);
		historico[0] = jogHumano;

		for(i = 1; i < K && jogHumano; i++){
			x = random(x);
			jogNancy = facil(x);

			verifica(jogNancy,jogHumano);

			printf("\nInsira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
			scanf("%d",&jogHumano);
			historico[i] = jogHumano;	
		}

		x = random(x);
		jogNancy = facil(x);

		/*agora eu começo a aplicar as condicionais*/
		for(i = K; jogHumano; i++){

			verifica(jogNancy,jogHumano);			
			
			x = random(x);
			jogNancy = medio(x,i);

			printf("\nInsira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
			scanf("%d",&jogHumano);
			
			historico[i%K] = jogHumano;

		}

	} else if(dif == 3){
		printf("ainda nao implementei hehehe\n");
	}

	printf(" ______________________ \n");
	printf("|     Quadro Geral     |\n");
	printf("|                      |\n");
	printf("| Nancy: %d vitórias.  |\n",vitNancy);
	printf("| Você: %d vitórias.   |\n",vitHumano);
	printf("| Empates: %d.         |\n",empates);
	printf("| Total: %d.           |\n",partidas);
	printf("|______________________|\n");	
	
	return 0;
}