#include "../Libs/arquivos.h"
#include "../Libs/lista_Processos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
// Vai ler o arquivo de teste
void ler(char nome[1000]){
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

    Vetor_Celula *vetor_celula;
    Lista_Processo lista_processo;
    srand((unsigned)time(NULL));
    
    if (file)
    {
        fscanf(file,"%d\n",&N);
        fscanf(file,"%d\n",&NLO);
    }
    criar_vetor_celula(&vetor_celula, N);
    organizacao_vetor(vetor_celula, &lista_processo, N);
    for (int i = 0; i < NLO; i++)
    {
        fscanf(file,"%d %d",&Op,&Qt);
        if (Op == 0){
            preenche_vetor(vetor_celula, &lista_processo, Qt);
        }
        if (Op == 1){
            retirar_menor_pid(vetor_celula, &lista_processo, Qt);
        }
    }
    fclose(file);
    libera_memoria(&vetor_celula);
}
// vai escrever o arquivo de saida
void escreve_arquivo_tempo(char nome[1000], clock_t tempo_execu){
    char arq_sai[] = ("Arquivo_saida.txt");
    char tempo[20];
    FILE *saida = fopen(arq_sai, "a");
    if(saida) {
        fputs(nome, saida);
        sprintf(tempo, " %f ", ((float)tempo_execu)/(float)CLOCKS_PER_SEC);
        fputs(tempo, saida);
        fprintf(saida,"segundos\n");
        fclose(saida);
        printf("\nARQUIVO DE SAIDA FOI ATUALIZADO!!!\n");
    } else
        printf("\nERRO ao abrir arquivo de saida!\n");
}