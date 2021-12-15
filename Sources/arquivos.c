#include "../Libs/arquivos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// Vai ler o arquivo de teste
void ler(char nome[]){
    FILE *file = fopen(nome,"r");
    if(file==NULL){
        printf("Erro para abrir o arquivo de leitura!!!!");
        exit(1);
    }
    int N;
    // Tamanho do vetor para cursores
    int NLO;
    //Número de linhas de operações especificadas abaixo
    int Op, Qt;
    // Op = 0 para inserção e 1 para remoção início
    // Qt = quantidade de vezes que a operação será realizada
    
    if (file)
    {
        fscanf(file,"%d\n",&N);
        fscanf(file,"%d\n",&NLO);
    }
    for (int i = 0; i < NLO; i++)
    {
        fscanf(file,"%d %d",&Op,&Qt);
        /*
        printf("OP=%d\n",Op);
        printf("QT=%d\n",Qt);
        printf("\n");*/
    }
    
    fclose(file);
}
// vai escrever o arquivo de saida
void escreve(char arquivo_saida[],clock_t tempo_execu ){
    char tempo[20];
    FILE *saida = fopen(arquivo_saida, "a");
    if(saida) {
        sprintf(tempo, "%f ", ((float)tempo_execu)/CLOCKS_PER_SEC);
        fputs(tempo, saida);
        fprintf(saida,"milisegundos\n");
        fclose(saida);

    } else
        printf("\nERRO ao abrir arquivo de saida!\n");
}