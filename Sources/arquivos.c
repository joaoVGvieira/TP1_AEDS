#include "../Libs/arquivos.h"
#include "../Libs/lista_Processos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
// Vai ler o arquivo de teste
void ler(){
    char nome[1000];
    printf("DIGITE O NOME DO ARQUIVO DE ENTRADA:");
    scanf(" %[^\n]s ",nome);
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
    //imprime_vetor(vetor_celula,&lista_processo, N);
    fclose(file);
}
// vai escrever o arquivo de saida
void escreve_arquivo_tempo(clock_t tempo_execu){
    char arquivo_saida[1000];
    printf("DIGITE O NOME DO ARQuIVO DE SAIDA: ");
    scanf(" %[^\n]s ",arquivo_saida);
    char tempo[20];

    FILE *saida = fopen(arquivo_saida, "w");
    if(saida) {
        sprintf(tempo, "%f ", ((float)tempo_execu)/CLOCKS_PER_SEC);
        fputs(tempo, saida);
        fprintf(saida,"milisegundos\n");
        fclose(saida);

    } else
        printf("\nERRO ao abrir arquivo de saida!\n");
}