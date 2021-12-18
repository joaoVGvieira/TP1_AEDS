#include <stdio.h>
#include <stdlib.h>
#include "Libs/arquivos.h"
#include "Libs/interativo.h"


int main(void){
    int operacao_sistema;
    clock_t tempo_execu;
    char nome[1000];
    tempo_execu = clock();
    //("arquivo_teste/teste.txt"); se for usar de outra pasta usa assim
    char arquivo_saida[1000];
    printf("\n");
    printf(
          " _________________(MENU PRINCIPAL)___________________ \n"
          "|                                                    |\n"
          "| ESCOLHA UMA DAS SEGUINTES FORMAS DE INICIALIZACAO: |\n"
          "|                                                    |\n"
          "| INTERATIVO = 1                                     |\n"
          "| POR ARQUIVO = 2                                    |\n"
          "| ENCERRAR OPERACOES = 0                             |\n"
          "|____________________________________________________|\n");
    printf("DIGITE A OPERACAO DESEJADA: ");

        //menu();
    scanf("%d",&operacao_sistema);
    switch (operacao_sistema) {
        case 0:
            break;
        case 1:
            menu_interativo();
            break;
        case 2:
            tempo_execu = clock();
             printf("DIGITE O NOME DO ARQUIVO DE ENTRADA: ");
             scanf(" %[^\n]s ",nome);
             ler(nome);
            tempo_execu =  clock()- tempo_execu;
            escreve_arquivo_tempo(nome,tempo_execu);
            break;  
        default:
            printf("\n\n-----Opção inválida!!!!-----\n\n");
        }   
    printf("\n\n-----Volte sempre!!!-----\n\n"); 
    system("pause");
    return 0;
}
