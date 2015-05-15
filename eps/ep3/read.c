#include <stdio.h>

int main(){
    
    FILE * entrada;
    FILE * saida;
    FILE * dicionario;
    int leitura, i,j,tamPal, tamDic,achei,errei, k,tot;
    char palAtual[100],dicAtual[100],text[10000];

    entrada = fopen("DECRYPT.IN","r");
    saida = fopen("DECRYPT.OUT","w");
    dicionario = fopen("dicionario.txt","r");
    leitura = 1;

    for(i = 0; leitura != EOF; i++){
       leitura = fscanf(entrada,"%c",&text[i]);
    }
    tot = i - 1;
    k = 0;
    errei = 0;

    
    while(k < tot && !errei){
        j = 0;
        leitura = 1;
        for(i = k; (text[i] != '\0' && text[i] != '_') && text[i] != '.'; i++){
            palAtual[j] = text[i];
            j++;
        }
        tamPal = j;
        k = i + 1;
        
        

        achei = 0;
        
        while(leitura != EOF && !achei){

            leitura = fscanf(dicionario,"%c",&dicAtual[0]);
            for(i = 1; dicAtual[i-1] != '\n'; i++)
                leitura = fscanf(dicionario,"%c",&dicAtual[i]);
            tamDic = i - 1;
            errei = 1;
            if(tamPal == tamDic && dicAtual[0] == palAtual[0]){
                errei = 0;
                for(i = 0; i < tamPal && !errei; i++){
                    if(dicAtual[i] != palAtual[i])
                        errei = 1;
                }
            }
            if(!errei)
                achei = 1;
        }
        rewind(dicionario);
    }

    if(achei)
        fprintf(saida, "ACHEI COROLHO\n");
    else
        fprintf(saida, "NAO ACHEI\n");

    fclose(entrada);
    fclose(saida); 

    return 0;
}