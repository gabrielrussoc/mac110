/*	********************************************************************* */
/*	Nome:	Gabriel de Russo e Carmo																																																																																			*/
/*	Numero	USP:	9298041																																																									*/
/*	Exercício-programa	2																																																																																																							*/
/*	********************************************************************* */

#include <stdio.h>
#define PEDRA 0
#define TESOURA 1
#define PAPEL 2
#define K 20

int vitHumano, vitNancy, empates, partidas, historico[K];
float score1, score2, score3;

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

/*
Com base nas estrategias de
http://www.dllu.net/programming/rps/
*/
void contaDificil(int jogNancy, int jogHumano){

	int e1,e2,e3;

	e1 = jogNancy;
	e2 = (e1+2)%3;
	e3 = (e2+2)%3;

	printf("H: %d E1: %d E2: %d E3:%d\n",jogHumano,e1,e2,e3);

	if(e1 == jogHumano){
		score2++;
		score3--;
	} else if(e2 == jogHumano){
		score1--;
		score3++;
	} else if(e3 == jogHumano){
		score1++;
		score2--; 
	}

	/*score1 = score1*0.9;
	score2 = score2*0.9;
	score3 = score3*0.9;*/

	printf("Scores: %f %f %f\n",score1,score2,score3);

}

int dificil(int jogNancy){

	if(score1 > score2 && score1 > score3)
		jogNancy = jogNancy;
	else if(score2 > score3 && score2 > score1)
		jogNancy = (jogNancy + 2)%3;
	else if(score3 > score1 && score3 > score2)
		jogNancy = ((jogNancy + 2)%3 + 2)%3;

	return jogNancy;

}

void verifica(int jogNancy, int jogHumano){

	if(jogNancy == PEDRA){
		printf("(Nancy) Pedra X");
	} else if (jogNancy == TESOURA){
		printf("(Nancy) Tesoura X");
	} else if (jogNancy == PAPEL){
		printf("(Nancy) Papel X");
	}


	if(jogHumano == PEDRA){
		printf(" Pedra (Voce)\n");
	} else if(jogHumano == TESOURA){
		printf(" Tesoura (Voce)\n");
	} else if(jogHumano == PAPEL){
		printf(" Papel (Voce)\n");
	}

	if(jogNancy == jogHumano){
		printf("Empate!\n");
		empates++;
	} else if(jogHumano - jogNancy == 1 || jogHumano - jogNancy == -2){
		printf("Nancy ganhou!\n");
		vitNancy++;
	} else {
		printf("Voce ganhou!\n");
		vitHumano++;
	}

	partidas++;

}

int main(){

	int jogNancy, jogHumano, i, dif;
	long x = 3;

	vitHumano = vitNancy = empates = partidas = 0;
	score1 = score2 = score3 = 0;
		
	printf("Escolha a dificuldade:\n");
	printf("1 - Fácil\n");
	printf("2 - Médio\n");
	printf("3 - Difícil\n");
	scanf("%d",&dif);

	printf("\n");

	/*MODO FACIL*/
	if(dif == 1){

		printf("Insira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
		scanf("%d",&jogHumano);
		jogHumano--;

		while(jogHumano >= 0){
			
			x = random(x);
			jogNancy = facil(x);
			verifica(jogNancy,jogHumano);

			printf("\nInsira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
			scanf("%d",&jogHumano);
			jogHumano--;

		}

	/*MODO MEDIO*/
	} else if(dif == 2){

		/*jogo aleatório nas K primeiras jogadas */
		printf("Insira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
		scanf("%d",&jogHumano);
		jogHumano--;
		historico[0] = jogHumano;
		x = random(x);
		jogNancy = facil(x);

		for(i = 1; i < K && jogHumano >= 0; i++){
			verifica(jogNancy,jogHumano);

			printf("\nInsira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
			scanf("%d",&jogHumano);
			jogHumano--;
			historico[i] = jogHumano;

			x = random(x);
			jogNancy = facil(x);	
		}
	
		/*agora eu começo a aplicar as condicionais*/
		for(i = K; jogHumano >= 0; i++){
			verifica(jogNancy,jogHumano);			
			
			x = random(x);
			jogNancy = medio(x,i);

			printf("\nInsira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
			scanf("%d",&jogHumano);
			jogHumano--;
			historico[i%K] = jogHumano;
		}

	/*MODO DIFICIL*/
	} else if(dif == 3){
		

		/*jogo aleatório nas K primeiras jogadas */
		printf("Insira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
		scanf("%d",&jogHumano);
		jogHumano--;
		historico[0] = jogHumano;
		x = random(x);
		jogNancy = facil(x);

		for(i = 1; i < K && jogHumano >= 0; i++){
			verifica(jogNancy,jogHumano);

			printf("\nInsira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
			scanf("%d",&jogHumano);
			jogHumano--;
			historico[i] = jogHumano;

			x = random(x);
			jogNancy = facil(x);	
		}
	
		/*agora eu começo a aplicar as condicionais*/
		for(i = K; jogHumano >= 0; i++){
			contaDificil(medio(x,i),jogHumano);	
			verifica(jogNancy,jogHumano);

			x = random(x);
			
			jogNancy = dificil(jogNancy);

			printf("\nInsira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
			scanf("%d",&jogHumano);
			jogHumano--;
			historico[i%K] = jogHumano;
		}		

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