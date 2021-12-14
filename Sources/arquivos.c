#include "../Libs/arquivos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ler(char nome[]){
    FILE *file = fopen(nome,"r");
    if(file==NULL){
        printf("Erro para abrir o arquivo!!!!");
        exit(1);
    }
    printf("\n\nAberto com sucesso!!!!\n\n");

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
        printf("OP=%d\nQT=%d\n",Op, Qt);
    }
    
    fclose(file);
}

