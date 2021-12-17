#include <stdio.h>
#include <stdlib.h>
#include "Libs/lista_Processos.h"
#include "Libs/arquivos.h"
#include "Libs/menu.h"
int main(void){
    int operacao_sistema;
    int N;
    clock_t tempo_execu;
    tempo_execu = clock();
    char nome[] = ("arquivo_teste/teste.txt"); 
    char arquivo_saida[]=("Teste_saida.txt");
    menu();
    scanf("%d",&operacao_sistema);
    switch (operacao_sistema) {
        case 0:
            printf("\n\n-----Volte sempre!!!-----\n\n"); 
            break;
        case 1:
            printf("DIGITE O TAMANHO N DO VETOR:");
            scanf("%d",&N);
            break;
        case 2:
            tempo_execu = clock();
            ler(nome);
            tempo_execu =  clock()- tempo_execu;
            escreve(arquivo_saida, tempo_execu);
            break;  
        default:
            printf("\n\n-----Opção inválida!!!!-----\n\n");
    }
    system("pause");
    return 0;
}
