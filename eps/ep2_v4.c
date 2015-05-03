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
void printaResultado(int jogadaNancy, int jogadaHumano){

    if(jogadaNancy == PEDRA)
        printf("(Nancy) Pedra X");
    else if (jogadaNancy == TESOURA)
        printf("(Nancy) Tesoura X");
    else if (jogadaNancy == PAPEL)
        printf("(Nancy) Papel X");

    if(jogadaHumano == PEDRA)
        printf(" Pedra (Voce)\n");
    else if(jogadaHumano == TESOURA)
        printf(" Tesoura (Voce)\n");
    else if(jogadaHumano == PAPEL)
        printf(" Papel (Voce)\n");

    if(jogadaNancy == jogadaHumano)
        printf("Empate!\n");
    else if(jogadaHumano - jogadaNancy == 1 || jogadaHumano - jogadaNancy == -2)
        printf("Nancy ganhou!\n");
    else
        printf("Voce ganhou!\n");
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
int medio(long long semente, int contPapel, int contTesoura, int total){
    /*a jogada da maquina é decidida com base nesses contadores nos contadores
    do algoritmo de predicao. Eu pego um aleatorio e coloco nos intervalos 
    calculados e jogo para ganhar*/

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
Usarei 3 meta-estrategias que, em exemplos, sao:
O algoritmo previu pedra, logo:
meta1: simplesmente jogar o que vence o previsto, no caso papel. 
meta2: o oponente antecipa meu papel (meta1) e joga tesoura, mas jogo pedra.
meta3: o oponente antecipa minha pedra (meta2) e joga papel, mas jogo tesoura.
O processo pode parecer infinito, mas uma vez que o oponente antecipar a tesoura
(meta3), eu jogo pedra (meta1), recomecando o ciclo.
Toda meta-estrategia roda no fundo e tem um score constantemente atualizado. 
A jogada escolhida eh a meta-estrategia com maior score momentaneo.*/
int dificil(int jogadaNancy, int score0, int score1, int score2){

    int meta[3], maior, indice;

    meta[0] = jogadaNancy;
    meta[1] = (meta[0]+1)%3;
    meta[2] = (meta[1]+1)%3;

    maior = score0;
    indice = 0;
    if(score1 > maior){
        maior = score1;
        indice = 1;
    }
    if(score2 > maior){
        maior = score2;
        indice = 2;
    }

    return meta[indice];
}

/*funcao auxiliar para o modo dificil*/
int desempenho(int meta, int jogadaHumano){

    if(jogadaHumano - meta == 1 || jogadaHumano - meta == -2)
        return 1;
    else if(meta - jogadaHumano == 1 || meta - jogadaHumano == -2)
        return -1;
    else
        return 0;
}

int main(){
    int vitoriasHumano, vitoriasNancy, empates, partidas;
    int jogadaNancy, jogadaHumano, i, j, dificuldade, auxiliar;
    int contPapel, contTesoura, total, historico[K], score0, score1, score2;
    long long semente = 3;

    /*inicializacoes*/
    vitoriasHumano = vitoriasNancy = empates = partidas = 0;
    score0 = score1 = score2 = auxiliar = 0;

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


    semente = random(semente);
    jogadaNancy = facil(semente);

    jogadaHumano = entradaHumano();
    historico[0] = jogadaHumano;

    /*as primeiras K sempre sao aleatorias, independente da dificuldade
    OBS: apesar de nao precisar do historico no facil, optei por salvar mesmo
    assim pois nao faria muita diferenca e eu evito mais um if*/
    for(i = 1; i < K && jogadaHumano >= 0; i++){
        printaResultado(jogadaNancy,jogadaHumano);

        partidas++;
        if(jogadaNancy == jogadaHumano)
            empates++;
        else if(jogadaHumano - jogadaNancy == 1 || jogadaHumano - jogadaNancy == -2)
            vitoriasNancy++;
        else
            vitoriasHumano++;

        semente = random(semente);
        jogadaNancy = facil(semente);

        jogadaHumano = entradaHumano();
        historico[i] = jogadaHumano;
    }

    for(i = K; jogadaHumano >= 0; i++){
        printaResultado(jogadaNancy,jogadaHumano);

        partidas++;
        if(jogadaNancy == jogadaHumano)
            empates++;
        else if(jogadaHumano - jogadaNancy == 1 || jogadaHumano - jogadaNancy == -2)
            vitoriasNancy++;
        else
            vitoriasHumano++;

        /*As dificuldades estao explicadas em mais detalhes nas funcoes*/
        semente = random(semente);

        if(dificuldade == 1)
            jogadaNancy = facil(semente);

        /*Algoritmo de prediçao: dado a ultima jogada do humano, eu procuro
        todas as vezes que ele a jogou e guardo a proxima num contador
        especifico (nao preciso de um contador para pedra pois eh justamente
        a diferenca do total pelos outros dois) - nao preciso dele no facil*/
        else if(dificuldade == 2 || dificuldade == 3){
            contPapel = contTesoura = total = 0;
            for(j = 0; j < K; j++){
                if(historico[j] == historico[(i - 1) % K]){
                    total++;
                    if(historico[(j + 1) % K] == PAPEL)
                       contPapel++;
                    else if(historico[(j + 1) % K] == TESOURA)
                        contTesoura++;
                }
            }
            if(dificuldade == 2)
                jogadaNancy = medio(semente,contPapel,contTesoura,total);
            else if(dificuldade == 3){
                auxiliar = medio(semente,contPapel,contTesoura,total);
                jogadaNancy = dificil(auxiliar, score0, score1, score2);
            }
        }

        jogadaHumano = entradaHumano();
        historico[i % K] = jogadaHumano;

        /*Atualizo os scores do modo dificil*/
        if(dificuldade == 3){
            score0 += desempenho(auxiliar,jogadaHumano);
            score1 += desempenho((auxiliar + 1) % 3,jogadaHumano);
            score2 += desempenho((auxiliar + 2) % 3,jogadaHumano);
        }
    }
    

    printf("\nResultados finais:\n");
    printf("Vitórias Nancy:  %.2f%% (%d)\n",(float) vitoriasNancy/partidas*100,vitoriasNancy);
    printf("Vitórias Humano: %.2f%% (%d)\n",(float) vitoriasHumano/partidas*100,vitoriasHumano);
    printf("Empates:         %.2f%% (%d)\n",(float) empates/partidas*100,empates); 
    printf("Partidas:        %d\n\n",partidas);
    if(vitoriasNancy > vitoriasHumano)
        printf("A máquina Nancy venceu!\n\n");
    else if(vitoriasNancy < vitoriasHumano)
        printf("Você venceu!\n\n");
    else
        printf("Que improvável! O jogo acabou empatado...\n\n");

    return 0;
}
