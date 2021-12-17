 #include <stdio.h>
 #include <stdlib.h>
 #include "../Libs/menu.h"

 void menu(){
        printf(
               "|                                                    |\n"
               "| ESCOLHA UMA DAS SEGUINTES FORMAS DE INICIALIZACAO: |\n"
               "|                                                    |\n"
               "| INTERATIVO = 1                                     |\n"
               "| POR ARQUIVO = 2                                    |\n"
               "| ENCERRAR OPERACOES = 0                             |\n"
               "|                                                    |\n");
        printf("DIGITE A OPERACAO DESEJADA: ");
    }

void menu_arquivo(){
       printf("1.digitar para nome do arquivo para leitura");
}
void menu_interativo(){
       printf(
               "|                                                    |\n"
               "|                                                    |\n"
               "|                                                    |\n"
               "| INSERIR O TAMANHO DO VETOR= 1                      |\n"
               "| IMPRIMI=3                                          |\n"
               "| VOLTA AO MENU PRINCIPAL = 0                        |\n"
               "|                                                    |\n");
       printf("DIGITE A OPERACAO DESEJADA: ");  
}