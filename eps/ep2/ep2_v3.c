/* ********************************************************************* 
Nome:   Gabriel de Russo e Carmo
Numero  USP:    9298041
Exercício-programa  2
********************************************************************* */

#include <stdio.h>
#define PEDRA 0
#define TESOURA 1
#define PAPEL 2
#define K 20
#define MAX 4294967296

int vitoriasHumano, vitoriasNancy, empates, partidas, historico[K], score[3];

/*Essa funcao gera sementes para as jogadas aleatorias
pelo metodo das congruencias lineares*/
long long random(long long semente){

    return ((semente * 22695477) + 1) % MAX;
}

/*Como existem varias entradas do jogador, para evitar copy-paste,
essa funçao faz a leitura e imprime a instrucao para o humano.
Eu subtraio um da jogada para poder trabalhar com modulo-3 no modo
dificil */
int entradaHumano(){

    int jogadaHumano;

    printf("\nInsira 1 (pedra), 2 (tesoura), 3 (papel) ou 0 para sair.\n");
    scanf("%d",&jogadaHumano);
    jogadaHumano--;

    return jogadaHumano;
}

/*Novamente para evitar copy-paste, a funçao apenas printa na tela
o resultado de cada rodada e marca no total para o final do
programa*/
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

/*Jogada da maquina no modo facil, simplesmente pega um aleatorio
e coloca-o no intervalo indicado para realizar a jogada*/
int facil(long long semente){

    if( (float) semente/MAX < 1.0/3 )
        return PEDRA;
    else if( (float) semente/MAX < 2.0/3 )
        return TESOURA;
    else
        return PAPEL;
}

/*A jogada do modo medio tenta prever a proxima jogada do humano com 
base na jogada anterior e um historico de jogadas de tamanho K.
O K escolhido foi 20, uma vez que apresentou resultados razoaveis quando
comparado com outros valores. Menores que isso podiam perder informaçao
importante e maiores podiam acumular informaçao prejudicial (pensando na
mente humana como adversario e nao em outro algoritmo)*/
int medio(long long semente, int i){

    int j, contPedra, contPapel, contTesoura, total;
    contPedra = contPapel = contTesoura = total = 0;

    /* se a anterior for pedra, eu procuro
    todas as vezes que ele jogou pedra e guardo a
    seguinte num contador*/
    if(historico[(i - 1) % K] == PEDRA){
        for(j = 0; j < K; j++){
            if(historico[j] == PEDRA){
                total++;
                if(historico[(j + 1) % K] == PEDRA)
                    contPedra++;
                else if(historico[(j + 1) % K] == PAPEL)
                    contPapel++;
                else if(historico[(j + 1) % K] == TESOURA)
                    contTesoura++;
            }
        }
    } 

    /*processo análogo no caso da anterior ser tesoura*/
    else if(historico[(i - 1) % K] == TESOURA){
        for(j = 0; j < K; j++){
            if(historico[j] == TESOURA){
                total++;
                if(historico[(j + 1) % K] == PEDRA)
                    contPedra++;
                else if(historico[(j + 1) % K] == PAPEL)
                    contPapel++;
                else if(historico[(j + 1) % K] == TESOURA)
                    contTesoura++;
            }
        }
    } 

    /*processo análogo no caso da anterior ser papel*/
    else if(historico[(i - 1) % K] == PAPEL){
        for(j = 0; j < K; j++){
            if(historico[j] == PAPEL){
                total++;
                if(historico[(j + 1) % K] == PEDRA)
                    contPedra++;
                else if(historico[(j + 1) % K] == PAPEL)
                    contPapel++;
                else if(historico[(j + 1) % K] == TESOURA)
                    contTesoura++;
            }
        }
    } 

    /*agora a jogada da maquina é decidida com base nesses contadores:
    eu pego um aleatorio e coloco nos intervalos calculados e jogo para ganhar*/

    /* chance do cara jogar papel */
    if( (float) semente/MAX <= (float) contPapel/total )
        return TESOURA;
    /* chance do cara jogar tesoura */
    else if( (float) semente/MAX <= (float) (contPapel + contTesoura)/total )
        return PEDRA;
    /* chance do cara jogar pedra */    
    else
        return PAPEL;
}

/*Com base nas estrategias de
http://www.ofb.net/~egnor/iocaine.html

O metodo dificil consiste no uso algoritmo de prediçao ja implementado
(modo medio) com o conceito de meta-estrategia. Basicamente, considera que
o humano pode prever a jogada da maquina, uma vez que o algoritmo de predicao 
eh bastante simples e facilmente contornavel - uma especie de defesa.
Existem 3 meta-estrategias que, em exemplos, sao:
O algoritmo previu pedra, logo:
meta1: simplesmente jogar o que vence o previsto, no caso papel. 
meta2: o oponente antecipa meu papel (meta1) e joga tesoura, mas jogo pedra.
meta3: o oponente antecipa minha pedra (meta2) e joga papel, mas jogo tesoura.
O processo pode parecer infinito, mas uma vez que o oponente antecipar a tesoura
(meta3), eu jogo pedra (meta1), recomecando o ciclo.
Toda meta-estrategia roda no fundo e tem um score constantemente atualizado (na 
funcao desempenho). A jogada escolhida eh a meta-estrategia com maior score 
momentaneo.*/
int dificil(int jogadaNancy){

    int meta[3], i, maior, indiceMaior;

    meta[0] = jogadaNancy;
    meta[1] = (meta[0]+1)%3;
    meta[2] = (meta[1]+1)%3;

    indiceMaior = 0;
    maior = score[0];
    for(i = 0; i < 3; i++){
        if(score[i] > maior){
            maior = score[i];
            indiceMaior = i;
        }
    }

    return meta[indiceMaior];
}

/*Essa funcao soma 1 para a meta-estrategia vencedora e -1 para a perdedora*/
void desempenho(int jogadaNancy, int jogadaHumano){

    int meta[3], i;

    meta[0] = jogadaNancy;
    meta[1] = (meta[0]+1)%3;
    meta[2] = (meta[1]+1)%3;

    for(i = 0; i < 3; i++){
        if(jogadaHumano - meta[i] == 1 || jogadaHumano - meta[i] == -2)
            score[i]++;
        else if(meta[i] - jogadaHumano == 1 || meta[i] - jogadaHumano == -2)
            score[i]--;
    }
}

int main(){
    int jogadaNancy, jogadaHumano, i, dificuldade, auxiliar;
    long long semente = 3;

    /*inicializacoes*/
    vitoriasHumano = vitoriasNancy = empates = partidas = 0;
    for(i = 0; i < 3; i++){
        score[i] = 0;
    }

    printf("\nBem-vindo ao famoso jogo do Pedra, Papel e Tesoura!\n\n");
    printf("Lembre-se que:\n");
    printf("Pedra ganha de tesoura\n");
    printf("Tesoura ganha de papel\n");
    printf("Papel ganha de de pedra\n\n");
    printf("Você enfrentará a máquina Nancy! Boa sorte!\n\n");
        
    printf("Escolha a dificuldade:\n");
    printf("1 - Fácil\n");
    printf("2 - Médio\n");
    printf("3 - Difícil\n");
    scanf("%d",&dificuldade);

    /*MODO FACIL*/
    if(dificuldade == 1){
        /*todas as jogadas sao aleatorias*/
        jogadaHumano = entradaHumano();

        while(jogadaHumano >= 0){            
            semente = random(semente);
            jogadaNancy = facil(semente);
            verificaResultado(jogadaNancy,jogadaHumano);

            jogadaHumano = entradaHumano();
        }

    /*MODO MEDIO*/
    } else if(dificuldade == 2){
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
    
        /*agora eu começo a aplicar condicionais explicadas na funcao medio*/
        for(i = K; jogadaHumano >= 0; i++){
            verificaResultado(jogadaNancy,jogadaHumano);           
            
            semente = random(semente);
            jogadaNancy = medio(semente,i);

            jogadaHumano = entradaHumano();
            historico[i % K] = jogadaHumano;
        }

    /*MODO DIFICIL*/
    } else if(dificuldade == 3){ 
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
    
        /*agora eu começo a aplicar o dificil, explicado na funcao dificil*/
        for(i = K; jogadaHumano >= 0; i++){
            verificaResultado(jogadaNancy,jogadaHumano);
            
            semente = random(semente);
            auxiliar = medio(semente,i);
            jogadaNancy = dificil(auxiliar);

            jogadaHumano = entradaHumano();
            historico[i % K] = jogadaHumano;

            /*atualizo os scores das meta-estrategias sempre*/
            desempenho(auxiliar,jogadaHumano);
        }
    }

    printf("\nResultados finais:\n");
    printf("Vitórias Nancy:  %.2f%% (%d)\n",(float) vitoriasNancy/partidas*100,vitoriasNancy);
    printf("Vitórias Humano: %.2f%% (%d)\n",(float) vitoriasHumano/partidas*100,vitoriasHumano);
    printf("Empates:         %.2f%% (%d)\n",(float) empates/partidas*100,empates); 
    printf("Partidas:        %d\n",partidas); 

    return 0;
}
