 #include <stdio.h>
 #include <stdlib.h>
 #include "../Libs/menu.h"

 void menu(){
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
    }



void menu_interativo(){
       int N,opcao;
       printf("DIGITE O TAMANHO N DO VETOR PARA INICIALIZA-LO:");
       scanf("%d",&N);
       do
       { 
       printf("\n");
       printf(  
               " _________________(MENU INTERATIVO)__________________\n"
               "|                                                    |\n"
               "| INSERIR  = 1                                       |\n"
               "| REMOVER  = 2                                       |\n"
               "| IMPRIMIR = 3                                       |\n"
               "| ENCERRAR OPERACOES = 0                             |\n"
               "|____________________________________________________|\n");
                printf("DIGITE A OPERACAO DESEJADA: ");
                scanf("%d",&opcao);
       } while (opcao!=0); 
}

void menu_arquivo(){
       int opcao;
       do
       { 
       printf("\n");
       printf(  
               " _________________(MENU ARQUIVO)_____________________\n"
               "|                                                    |\n"
               "| IMPRIMIR = 1                                       |\n"
               "| ENCERRAR OPERACOES = 0                             |\n"
               "|____________________________________________________|\n");
                printf("DIGITE A OPERACAO DESEJADA: ");
                scanf("%d",&opcao);
       } while (opcao!=0); 
}
