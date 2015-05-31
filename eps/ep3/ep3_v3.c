/* ********************************************************************* 
Nome:   Gabriel de Russo e Carmo
Numero  USP:    9298041
Exercício-programa  3
********************************************************************* */

#include <stdio.h>
#define MAX 15000
#define TRUE 1
#define FALSE 0

int mdc(int a, int b);
int mod28(int a);
void textoPNumero(char ciphertext[MAX], int ciphercode[MAX], int n);
void numeroPTexto(char plaintext[MAX], int plaincode[MAX], int n);
void decripta(int plaincode[MAX], int ciphercode[MAX], int n, int k);
int pegaPalavra(int *p, int *tam, char plaintext[MAX], char palavraAtual[MAX], int n);
int procuraDicionario(FILE *dicionario, char palavraAtual[50], int tamanhoPal);

int main(){

    int chaves[300], ciphercode[MAX], plaincode[MAX], posicao, encontrei,
        errei, i, n, k, qtdChaves, valido, tamanhoPal;
    char ciphertext[MAX], plaintext[MAX], palavraAtual[50];


    FILE * entrada;
    FILE * saida;
    FILE * dicionario;
    entrada = fopen("DECRYPT.IN","r");
    saida = fopen("DECRYPT.OUT","w");
    dicionario = fopen("dicionario.txt","r");

    /*Leio a entrada e conto seu tamanho*/
    for(n = 0; fscanf(entrada,"%c",&ciphertext[n]) != EOF; n++);

    /*Correcao para alguns editores de texto que adicionam '\n' ao final da linha*/
    if(ciphertext[n-1] == '\n')
        n--;

    /*Pego todas as possiveis chaves*/
    qtdChaves = 0;
    for(k = 1; k < 301; k++){
        if(mdc(k,n) == 1){
            chaves[qtdChaves] = k;
            qtdChaves++;
        }
    }

    /*converto o texto em codigo numerico*/
    textoPNumero(ciphertext, ciphercode, n);

    /*testo todas as chaves ate encontrar uma frase valida*/
    valido = FALSE;
    for(i = 0; i < qtdChaves && !valido; i++){
        k = chaves[i];

        /*para cada chave, eu decripto o codigo numerico e o coverto para texto*/
        decripta(plaincode, ciphercode, n, k);
        numeroPTexto(plaintext, plaincode, n);
        
        /*Vou procurar todas as palavras do input no dicionario.
        Paro de procurar quando acabarem as palavras ou quando alguma nao for
        encontrada*/
        posicao = errei = 0;
        while(pegaPalavra(&posicao, &tamanhoPal, plaintext, palavraAtual, n) && !errei){
            
            /*Procuro a palavara no dicionario*/
            encontrei = procuraDicionario(dicionario, palavraAtual, tamanhoPal);

            /*Se nao encontrei, minha chave esta errada*/
            if(!encontrei)
                errei = TRUE;
        }

        /*se eu encontrei todas as palavras, obviamente nao errei nenhuma, logo
        minha frase é valida e eu nao preciso mais procurar chaves*/
        if(!errei)
            valido = TRUE;

    }
    /*agora imprimo a frase decodificada com a chave encontrada*/
    if(valido)
        for(i = 0; i < n; i++)
            fprintf(saida, "%c",plaintext[i]);
    else
        fprintf(saida, "Eu falhei na decodificacao :(");

    fclose(entrada);
    fclose(saida);
    fclose(dicionario);

    return 0;
}

/*Funcao que calcula o mdc*/
int mdc(int a, int b) {
    
    int resto, divisor, dividendo;
    divisor = a;
    dividendo = b;

    while(divisor != 0){
        resto = dividendo % divisor;
        dividendo = divisor;
        divisor = resto;
    }

    return dividendo;
}

/*Funcao que faz a operacao modulo-28*/
int mod28(int a){
    
    int res;
    
    if(a%28 >= 0)
        res = a % 28;
    else
        res = a % 28 + 28;

    return res;
}

/*Converte texto para codigo numerico, como no enunciado*/
void textoPNumero(char ciphertext[MAX], int ciphercode[MAX], int n){
    
    int i;

    for(i = 0; i < n; i++){
        if(ciphertext[i] == '_')
            ciphercode[i] = 0;
        else if(ciphertext[i] == '.')
            ciphercode[i] = 27;
        else
            ciphercode[i] = ciphertext[i] - 'A' + 1;
    }
}

/*Analogo a anterior, mas converte codigo numerico para texto*/
void numeroPTexto(char plaintext[MAX], int plaincode[MAX], int n){

    int i;

    for(i = 0; i < n; i++){
        if(plaincode[i] == 0)
            plaintext[i] = '_';
        else if(plaincode[i] == 27)
            plaintext[i] = '.';
        else
            plaintext[i] = plaincode[i] + 'A' - 1;     
    }
}

/*Aplica o 'detwist', basicamente o inverso do twist descrito no enunciado.
Esse metodo só funciona pois existe uma bijeção na funçao*/
void decripta(int plaincode[MAX], int ciphercode[MAX], int n, int k){

    int i;

    for(i = 0; i < n; i++)
        plaincode[(k * i) % n] = mod28(ciphercode[i] + i);
}


/*Essa funcao pega cada palavra do texto decodificado para poder procura-la no
dicionario, retorna false quando acabaram as palavras. Constantemente atualiza
a ultima posicao do input*/
int pegaPalavra(int *p, int *tam, char plaintext[MAX], char palavraAtual[MAX], int n){

    int i = 0;

    /*Se a ultima posicao estiver fora do input, nao ha mais palavras*/
    if(*p >= n)
        return FALSE;

    /*Vou as letras ate chegar num '.', '_' ou '\0'*/
    while(plaintext[*p] != '.' && plaintext[*p] != '_' && plaintext[*p] != '\0'){
        palavraAtual[i] = plaintext[*p];
        i++;
        *p = *p + 1;
    }

    /*O tamanho da palavra é o numero de letras*/
    *tam = i;

    /*Atualizo a ultima posicao pulando os 'nao letras'*/
    while(plaintext[*p] == '.' || plaintext[*p] == '_')
        *p = *p + 1;

    /*Retorno true para indicar que ainda existe uma palavra*/
    return TRUE;

}

/*Essa funcao pega palavra por palavra do dicionario e compara com uma palavra
dada. Retorna true se encontrar e false caso contrario*/
int procuraDicionario(FILE *dicionario, char palavraAtual[50], int tamanhoPal){

    char dicAtual[50];
    int tamanhoDic, i, encontrei, errado;
    encontrei = 0;
    errado = 1;

    while(fscanf(dicionario,"%c",&dicAtual[0]) != EOF && !encontrei){
        for(i = 1; dicAtual[i-1] != '\n'; i++){
            fscanf(dicionario,"%c",&dicAtual[i]);
            /*se eu ler um hífen, eu volto uma posição para ignora-lo*/
            if(dicAtual[i] == '-')
                i--;
        }
        /*Subtraio pois li até o '\n' */
        tamanhoDic = i - 1;

        /*Se tiverem o mesmo tamanho e mesma letra inicial, comparo tudo*/
        if(tamanhoDic == tamanhoPal && dicAtual[0] == palavraAtual[0]){
            errado = 0;
            for(i = 1; i < tamanhoDic && !errado; i++)
                if(palavraAtual[i] != dicAtual[i])
                    errado = 1;
        }

        if(!errado)
            encontrei = TRUE;
    }

    rewind(dicionario);

    if(encontrei)
        return TRUE;
    else
        return FALSE;

}
