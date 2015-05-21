#include <stdio.h>
#define MAX 15000
#define TRUE 1
#define FALSE 0

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

int mod28(int a){
    int res;
    if(a%28 >= 0)
        res = a % 28;
    else
        res = a % 28 + 28;

    return res;
}

int main(){

    FILE * entrada;
    FILE * saida;
    FILE * dicionario;
    entrada = fopen("DECRYPT.IN","r");
    saida = fopen("DECRYPT.OUT","w");
    dicionario = fopen("dicionario.txt","r");

    int chaves[300], ciphercode[MAX], plaincode[MAX], leitura, encontrei, diferente;
    int errei, m, i, j, p, n, k, qtdChaves, valido, tamanhoPal, tamanhoDic;
    char ciphertext[MAX], plaintext[MAX], palavraAtual[50], dicAtual[50];

    qtdChaves = 0;
    p = 0;
    valido = FALSE;

    /*Leio a entrada e conto seu tamanho*/
    leitura = fscanf(entrada,"%c",&ciphertext[0]);
    for(n = 1; leitura != EOF; n++)
        leitura = fscanf(entrada,"%c",&ciphertext[n]);
    n = n - 1;

    /*Pego todas as possiveis chaves*/
    for(k = 1; k < 301; k++){
        if(mdc(k,n) == 1){
            chaves[qtdChaves] = k;
            qtdChaves++;
        }
    }

    /*converto o texto em codigo numerico*/
    for(i = 0; i < n; i++){
        if(ciphertext[i] == '_')
            ciphercode[i] = 0;
        else if(ciphertext[i] == '.')
            ciphercode[i] = 27;
        else
            ciphercode[i] = ciphertext[i] - 'A' + 1;
    }

    /*testo todas as chaves ate encontrar uma frase valida*/
    for(j = 0; j < qtdChaves && !valido; j++){
        k = chaves[j];

        /*para cada chave, eu decripto o codigo numerico e o coverto para texto*/
        for(i = 0; i < n; i++){
            plaincode[(k * i) % n] = mod28(ciphercode[i] + i);

            if(plaincode[(k * i) % n] == 0)
                plaintext[(k * i) % n] = '_';
            else if(plaincode[(k * i) % n] == 27)
                plaintext[(k * i) % n] = '.';
            else
                plaintext[(k * i) % n] = plaincode[(k * i) % n] + 'A' - 1;
        }
        
        /*Vou checar se todas as palavras obtidas estao no dicionario*/
        i = errei = 0;
        while(i < n && !errei){
            m = 0;
            /*Cada palavra termina em '.', '_' ou '\0'. Pego uma por uma*/ 
            while((plaintext[i] != '.' && plaintext[i] != '_') && plaintext[i] != '\0'){
                palavraAtual[m] = plaintext[i];
                i++;
                m++;
            }
            tamanhoPal = m;
            /*Atualizo o contador para pular os caracteres especiais entre as 
            palavras*/
            while(plaintext[i] == '.' || plaintext[i] == '_')
                i++;

            /*Verifico se a palavra atual esta no dicionario, assumindo que nao
            esta. Se eu encontrar a palavra, ou seja, se existir uma palavra no
            dicionario que nao tem nenhuma letra diferente, eu paro de procurar
            e vejo a proxima.*/
            encontrei = FALSE;
            leitura = 1;
            while(leitura != EOF && !encontrei){
                /*pego cada palavra do dicionario e seu tamanho*/
                leitura = fscanf(dicionario,"%c",&dicAtual[0]);
                for(p = 1; dicAtual[p-1] != '\n'; p++)
                    leitura = fscanf(dicionario,"%c",&dicAtual[p]);
                tamanhoDic = p - 1;
                /*assumo q sao diferentes*/
                diferente = TRUE;
                /*se tiverem o mesmo tamanho e mesma letra eu comparo melhor*/
                if(tamanhoDic == tamanhoPal && palavraAtual[0] == dicAtual[0]){
                    /*nesse caso, assumo que sao iguais*/
                    diferente = FALSE;
                    for(p = 1; p < tamanhoDic && !diferente; p++){
                        /*se alguma letra for diferente, eu paro*/
                        if(dicAtual[p] != palavraAtual[p])
                            diferente = TRUE;
                    }
                }
                /*se nenhuma letra for diferente, eu encontrei*/
                if(!diferente)
                    encontrei = TRUE;
            }

            /*se eu nao encontrei pelo menos uma, eu errei e passo para proxima
            chave K*/
            if(!encontrei)
                errei = TRUE;

            rewind(dicionario);
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


    return 0;
}