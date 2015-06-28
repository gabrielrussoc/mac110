/* ********************************************************************* 
Nome:   Gabriel de Russo e Carmo
Numero  USP:    9298041
Exercício-programa  4
********************************************************************* */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define MAX 507

/*Funçao que insere um par de coordenadas na fila*/
void insereFila(int fila[MAX][2], int *fim, int i, int j){
    fila[*fim][0] = i;
    fila[*fim][1] = j;
    *fim = (*fim + 1) % MAX;
}

/*Funçao que remove um par da fila (apenas anda uma posiçao do ponteiro ini)*/
void removeFila(int *ini){
    *ini = (*ini + 1) % MAX;
}

/*Funcao que calcula modulo*/
int mod(int a, int n){
    int res;

    if(a % n >= 0)
        res = a % n;
    else
        res = a % n + n;

    return res;
}

/*Semelhante a da fila, essa funçao insere um par na pilha*/
void inserePilha(int pilha[MAX][2], int *topo, int i, int j){       
    *topo = *topo + 1;
    pilha[*topo][0] = i;
    pilha[*topo][1] = j;
}

/*Essa funcao remove um par da pilha, voltando o ponteiro topo*/
void removePilha(int *topo){
    *topo = *topo - 1;
}

/*Essa funcao me retorna um valor que me permite desempilhar um certo
par. Retorna true se existir um caminho ainda nao visitado e false caso
contrario*/
int ramificado(int ramo[MAX], int topo){
    if(ramo[topo] == 0)
        return FALSE;
    else
        return TRUE;
}

int main(){
    
    int n, m, i, j, k, valor, saida, cont;
    int i_saida, j_saida, i_thomas, j_thomas;
    int ini, fim, topo;
    int tab[MAX][MAX], fila[MAX][2], pilha[MAX][2], ramo[MAX];

    FILE * entrada;
    entrada = fopen("labirinto.txt","r");

    saida = 0;
    ini = fim = 0;
    topo = -1;

    /*Leio o par de coordenadas do Thomas e coloco-os numa fila*/
    fscanf(entrada,"%d %d",&i_thomas,&j_thomas);
    insereFila(fila,&fim,i_thomas,j_thomas);

    /*Leio as coordenadas da saida*/
    fscanf(entrada,"%d %d",&i_saida,&j_saida);

    /*Leio o tamanho da matriz*/
    fscanf(entrada,"%d %d",&n,&m);

    /*Dado o tamanho da matriz, leio-a e guardo na matriz 'tab'*/
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            fscanf(entrada,"%d",&tab[i][j]);

    /*Na posiçao do thomas, eu marco no tabuleiro um valor diferente de
    qualquer outro possivel para nao preenche-lo equivocadamente.*/
    tab[i_thomas][j_thomas] = -7;

    /*Enquanto a fila contiver pares E eu nao achar a saida, eu procuro
    em posicoes adjacentes as que ja estao na fila*/
    while(mod(fim-ini,MAX) && !saida){
        /*Pego as coordenadas do par na frente da fila e o removo*/
        i = fila[ini][0];
        j = fila[ini][1];
        removeFila(&ini);

        /*Se esse par for o primeiro, guardo o valor de preenchimento 
        adjacente como 1*/
        if(i == i_thomas && j == j_thomas)
            valor = 1;
        /*Caso contrario simplesmente pego o sucessor do atual*/
        else
            valor = tab[i][j]+1;

        /*Se o par atual for a saída, o loop para*/
        if(i == i_saida && j == j_saida)
            saida = 1;

        /*Caso contrario, para as quatro posicoes adjacentes eu vejo
        se é um caminho válido (nao é uma parede, ainda nao foi marcado e
        está dentro da matriz).
        Se for, eu coloco o par na fila e atualizo seu valor com a variavel
        'valor' que eu calculei anteriormente.*/
        else {
            if(i + 1 < n){
                if(tab[i+1][j] == 0){
                    insereFila(fila,&fim,i+1,j);
                    tab[i+1][j] = valor;
                }
            }
            if(i - 1 >= 0){
                if(tab[i-1][j] == 0){
                    insereFila(fila,&fim,i-1,j);
                    tab[i-1][j] = valor;
                }
            }
            if(j + 1 < m){
                if(tab[i][j+1] == 0){
                    insereFila(fila,&fim,i,j+1);
                    tab[i][j+1] = valor;
                }
            }
            if(j - 1 >= 0){
                if(tab[i][j-1] == 0){
                    insereFila(fila,&fim,i,j-1);
                    tab[i][j-1] = valor;
                }
            }
        }

    }

    /*Se eu percorri todos os caminhos possiveis e nao cheguei na saída,
    nao há saída.*/
    if(!saida)
        printf("Não existe caminho entre Thomas e a saída.\n");

    /*Se eu cheguei na saída, existe pelo menos um caminho e vou em busca
    de todos os possíveis. Faço isso empilhando todos os caminhos da saída para
    o começo. Guardo num vetor chamado 'ramo' (onde cada posicao é uma posicao do
    caminho) a soma dos seguintes valores:
        1 - se subir é um caminho possível;
        2 - se ir p/ direita é possível;
        4 - se ir p/ baixo é possível;
        8 - se ir p/ esquerda é possível;
    Por padrao, eu sigo a ordem cima-direita-baixo-esquerda p/ cada bifurcação.
    Uma vez escolhido o caminho, eu subtraio seu valor do vetor 'ramo' e sigo.
    Esse vetor é a minha condição principal para desempilhar certa parte
    do caminho. Se ele nao for 0, quer dizer que ainda há um caminho nao
    vistado, logo começo a reempilhar a partir deste ponto fazendo novamente
    todas as somas p/ os caminhos subsequentes.
    OBS: É fácil ver que aquela soma é sempre única para um único conjunto de
    caminhos possíveis*/
    else {
        /*Como dito, começo da saída e empilho*/
        i = i_saida;
        j = j_saida;
        inserePilha(pilha,&topo,i,j);

        /*Volto o valor da posiçao do Thomas para 0 para conseguir
        acessa-la*/
        tab[i_thomas][j_thomas] = 0;

        /*Zero meu vetor de ramificacoes*/
        for(k = 0; k < MAX; k++)
            ramo[k] = 0;

        /*Enquanto minha pilha nao esvaziar, eu tenho um novo caminho
        OBS: O ponteiro 'topo' aponta para a última posição ocupada, logo
        a pilha está vazia quando ele valer -1*/
        while(topo >= 0){

            /*Enquanto eu nao chegar no começo, eu empilho*/
            while(i != i_thomas || j != j_thomas){

                /*A variável valor guarda o valor atual -1, para eu saber
                para onde ir*/
                valor = tab[i][j] - 1;
                /*Inicializo a soma de caminhos já citada em 0*/
                cont = 0;

                /*Se nao existir nenhuma bifurcação ja salva, eu atualizo
                o vetor. Caso exista, quer dizer que já fiz esse cálculo
                para determinado caminho entao nao posso atualiza-lo, pois
                estou voltando para seguir um novo caminho possivel a partir
                deste ponto.*/
                if(ramo[topo] == 0){
                    /*Checo se posso ir para cima*/
                    if(i - 1 >= 0)
                        if(tab[i-1][j] == valor)
                            cont += 1;

                    /*Para a direita*/
                    if(j + 1 < m)
                        if(tab[i][j+1] == valor)
                            cont += 2;

                    /*Para baixo*/
                    if(i + 1 < n)
                        if(tab[i+1][j] == valor)
                            cont += 4;

                    /*Para a esquerda*/
                    if(j - 1 >= 0)
                        if(tab[i][j-1] == valor)
                            cont += 8;

                    ramo[topo] = cont;
                }

                /*Nessa parte, a partir das somas calculadas, eu tomo as minhas
                decisoes, seguindo o padrao cima-direita-baixo-esquerda*/

                /*Se a soma for impar, posso ir p/ cima e subtraio 1 para indicar
                que fui*/
                if(ramo[topo] % 2 != 0){
                    i = i - 1;
                    ramo[topo] -= 1;
                }

                /*Se a soma nao for multiplo de 4, posso ir p/ direita e subtraio 2
                p/ indicar que fui*/
                else if(ramo[topo] % 4 != 0){
                    j = j + 1;
                    ramo[topo] -= 2;
                }

                /*Se nao for multiplo de 8, vou para baixo e subtraio 4*/
                else if(ramo[topo] % 8 != 0){
                    i = i + 1;
                    ramo[topo] -= 4;
                }

                /*Obviamente, se nao fui para nenhum dos anterior, vou p/ 
                esquerda e subtraio 8.*/
                else {
                    j = j - 1;
                    ramo[topo] -= 8;
                }

                /*Uma vez tomada essa decisão, empilho este par*/
                inserePilha(pilha,&topo,i,j);
            }

            /*Aqui eu cheguei na posição do Thomas, logo tenho um caminho.
            Vou imprimi-lo*/
            printf("(%d, %d)",pilha[topo][0],pilha[topo][1]);
            for(k = topo - 1; k >= 0; k--){
                printf(" -> (%d, %d)",pilha[k][0],pilha[k][1]);
                /*Um pequeno hack para nao estourar 80 colunas*/
                if((topo - k) % 7 == 0) printf("\n");
            }
            printf("\n-----------------------\n");

            /*Desempilho o par do Thomas (que está no topo da pilha)*/
            removePilha(&topo);
            /*Posso desempilhar enquanto existir pares na pilha E nenhum deles
            seja uma bifurcação*/
            while(topo >= 0 && !ramificado(ramo,topo))
                removePilha(&topo);

            /*Se a pilha nao esvaziou, quer dizer que tenho uma bifurção
            a partir deste ponto, logo repito todo o processo a partir
            daqui*/
            if(topo >= 0){
                i = pilha[topo][0];
                j = pilha[topo][1];
            }
        }
    }

    fclose(entrada);

    return 0;
}