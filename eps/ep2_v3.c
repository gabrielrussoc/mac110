/*  ********************************************************************* */
/*  Nome:   Gabriel de Russo e Carmo                                                                                                                                                                                                                                                                                                                                            */
/*  Numero  USP:    9298041                                                                                                                                                                                                                                 */
/*  Exercício-programa  2                                                                                                                                                                                                                                                                                                                                                                                                                           */
/*  ********************************************************************* */

#include <stdio.h>
#define PEDRA 0
#define TESOURA 1
#define PAPEL 2
#define K 20

int vitoriasHumano, vitoriasNancy, empates, partidas, historico[K];
int score[6];

long random(long semente){
    int a = 22695477;
    int b = 1;
    long m = 4294967296;

    return ((semente * a) + b) % m;
}

int entradaHumano(){
    int jogadaHumano;

    printf("\nInsira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
    scanf("%d",&jogadaHumano);
    jogadaHumano--;

    return jogadaHumano;
}

void verificaResultado(int jogadaNancy, int jogadaHumano){
    if(jogadaNancy == PEDRA){
        printf("(Nancy) Pedra X");
    } else if (jogadaNancy == TESOURA){
        printf("(Nancy) Tesoura X");
    } else if (jogadaNancy == PAPEL){
        printf("(Nancy) Papel X");
    }

    if(jogadaHumano == PEDRA){
        printf(" Pedra (Voce)\n");
    } else if(jogadaHumano == TESOURA){
        printf(" Tesoura (Voce)\n");
    } else if(jogadaHumano == PAPEL){
        printf(" Papel (Voce)\n");
    }

    if(jogadaNancy == jogadaHumano){
        printf("Empate!\n");
        empates++;
    } else if(jogadaHumano - jogadaNancy == 1 || jogadaHumano - jogadaNancy == -2){
        printf("Nancy ganhou!\n");
        vitoriasNancy++;
    } else {
        printf("Voce ganhou!\n");
        vitoriasHumano++;
    }

    partidas++;
}

int facil(long semente){
    int jogadaNancy;
    long m = 4294967296;

    if( (float) semente/m < 1.0/3 ){
        jogadaNancy = PEDRA;
    }   
    else if( (float) semente/m < 2.0/3 ){
        jogadaNancy = TESOURA;
    }   
    else if( (float) semente/m < 1 ){
        jogadaNancy = PAPEL;
    }

    return jogadaNancy;
}

int medio(long semente, int i){
    int j, jogadaNancy, contPedra, contPapel, contTesoura, total;
    long m = 4294967296;
    contPedra = contPapel = contTesoura = total = 0;

    /* se a anterior for pedra, eu procuro
    todas as vezes que ele jogou pedra e guardo a
    seguinte num contador*/
    if(historico[(i-1)%K] == PEDRA){
        for(j = 0; j < K; j++){
            if(historico[j] == PEDRA){
                total++;
                if(historico[(j+1)%K] == PEDRA)
                    contPedra++;
                else if(historico[(j+1)%K] == PAPEL)
                    contPapel++;
                else if(historico[(j+1)%K] == TESOURA)
                    contTesoura++;
            }
        }
    } 

    /*processo análogo no caso da anterior ser tesoura*/
    else if(historico[(i-1)%K] == TESOURA){
        for(j = 0; j < K; j++){
            if(historico[j] == TESOURA){
                total++;
                if(historico[(j+1)%K] == PEDRA)
                    contPedra++;
                else if(historico[(j+1)%K] == PAPEL)
                    contPapel++;
                else if(historico[(j+1)%K] == TESOURA)
                    contTesoura++;
            }
        }
    } 

    /*processo análogo no caso da anterior ser papel*/
    else if(historico[(i-1)%K] == PAPEL){
        for(j = 0; j < K; j++){
            if(historico[j] == PAPEL){
                total++;
                if(historico[(j+1)%K] == PEDRA)
                    contPedra++;
                else if(historico[(j+1)%K] == PAPEL)
                    contPapel++;
                else if(historico[(j+1)%K] == TESOURA)
                    contTesoura++;
            }
        }
    } 

    /*agora a jogada da maquina é decidida com base nesses contadores:
    eu pego um aleatorio e coloco */

    /* chance do cara jogar papel */
    if( (float) semente/m < (float) contPapel/total )
        jogadaNancy = TESOURA;
    /* chance do cara jogar tesoura */
    else if( (float) semente/m < (float) (contPapel + contTesoura)/total )
        jogadaNancy = PEDRA;
    /* chance do cara jogar pedra */    
    else if( (float) semente/m <= (contPapel + contTesoura + contPedra)/total )
        jogadaNancy = PAPEL;

    return jogadaNancy;
}

/*
Com base nas estrategias de
http://www.dllu.net/programming/rps/
*/

int desempenho(int meta, int jogadaHumano){
    if(meta == jogadaHumano)
        return 0;
    else if(meta - jogadaHumano == 2 || meta - jogadaHumano == -1)
        return 1;
    else
        return -1;
}

int dificil(int jogadaNancy, int jogadaHumano){

    int meta[6],maior,ind,i;
    //previ que ele vai jogar pedra
    meta[0] = jogadaNancy; //2 papel
    //ele sabe que eu previ e vou jogar papel, entao me antecipa e tesoura
    meta[1] = (meta[0]+1)%3; //0 pedra
    //ele sabe que eu sei que ele vai jogar tesoura, entao joga papel
    meta[2] = (meta[1]+1)%3; //1 tesoura

    //agora eu troco de lugar com ele

    //ele previu que eu jogaria papel, logo deve jogar tesoura
    meta[3] = (meta[0]+1)%3; //1 tesoura
    //ele sabe que eu tento me antecipar e jogar pedra, entao joga papel
    meta[4] = (meta[3]+1)%3; //2 papel
    //ele sabe que eu tento antecipa-lo de novo e jogo papel, entao joga pedra
    meta[5] = (meta[4]+1)%3; //0 pedra

    maior = score[0];
    ind = 0;
    for(i = 1; i < 6; i++){
        if(score[i] > maior){
            maior = score[i];
            ind = i;
        }
    }

    jogadaNancy = meta[ind];

    for(i = 0; i < 6; i++){
        score[i] += desempenho(meta[i],jogadaHumano);
    }

    return jogadaNancy;
}

int main(){
    int jogadaNancy, jogadaHumano, i, dif;
    long semente = 2;

    vitoriasHumano = vitoriasNancy = empates = partidas = 0;
    
    for(i = 0; i < 6; i++){
        score[i] = 0;
    }
        
    printf("Escolha a dificuldade:\n");
    printf("1 - Fácil\n");
    printf("2 - Médio\n");
    printf("3 - Difícil\n");
    scanf("%d",&dif);

    /*MODO FACIL*/
    if(dif == 1){
        /*todas as jogadas sao aleatorias*/
        jogadaHumano = entradaHumano();

        while(jogadaHumano >= 0){            
            semente = random(semente);
            jogadaNancy = facil(semente);
            verificaResultado(jogadaNancy,jogadaHumano);

            jogadaHumano = entradaHumano();
        }

    /*MODO MEDIO*/
    } else if(dif == 2){
        /*primeiramente joga-se aleatoriamente as K primeiras jogadas,
        sempre guardando o movimento do humano*/
        semente = random(semente);
        jogadaNancy = facil(semente);

        jogadaHumano = entradaHumano();
        historico[0] = jogadaHumano;

        for(i = 1; i < K && jogadaHumano >= 0; i++){
            verificaResultado(jogadaNancy,jogadaHumano);

            semente = random(semente);
            jogadaNancy = facil(semente);

            jogadaHumano = entradaHumano();
            historico[i] = jogadaHumano;
        }
    
        /*agora eu começo a aplicar as condicionais explicadas na funcao medio*/
        for(i = K; jogadaHumano >= 0; i++){
            verificaResultado(jogadaNancy,jogadaHumano);           
            
            semente = random(semente);
            jogadaNancy = medio(semente,i);

            jogadaHumano = entradaHumano();
            historico[i%K] = jogadaHumano;
        }

    /*MODO DIFICIL*/
    } else if(dif == 3){ 
        /*jogo aleatório nas K primeiras jogadas, como no medio*/
        semente = random(semente);
        jogadaNancy = facil(semente);

        jogadaHumano = entradaHumano();
        historico[0] = jogadaHumano;

        for(i = 1; i < K && jogadaHumano >= 0; i++){
            verificaResultado(jogadaNancy,jogadaHumano);

            semente = random(semente);
            jogadaNancy = facil(semente);

            jogadaHumano = entradaHumano();
            historico[i] = jogadaHumano;
        }
    
        /*agora eu começo a aplicar as condicionais explicadas na funcao medio*/
        for(i = K; jogadaHumano >= 0; i++){
            verificaResultado(jogadaNancy,jogadaHumano);           
            
            semente = random(semente);
            jogadaNancy = dificil(medio(semente,i),jogadaHumano);

            jogadaHumano = entradaHumano();
            historico[i%K] = jogadaHumano;
        }
    }

    printf("\nResultados finais:\n");
    printf("Vitórias Nancy:  %.2f%% (%d)\n",(float) vitoriasNancy/partidas*100,vitoriasNancy);
    printf("Vitórias Humano: %.2f%% (%d)\n",(float) vitoriasHumano/partidas*100,vitoriasHumano);
    printf("Empates:         %.2f%% (%d)\n",(float) empates/partidas*100,empates); 
    printf("Partidas:        %d\n",partidas); 
    
    for(i = 0; i < 6; i++)
        printf("%d ",score[i]);

    printf("\n");

    return 0;

}