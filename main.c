#include <stdio.h>
#include <stdlib.h>
#include "Libs/lista_Processos.h"
#include "Libs/arquivos.h"
#include "Libs/menu.h"
int main(void){

    int operacao_sistema;
    while (operacao_sistema!=0)
    {
        menu();
        scanf("%d",&operacao_sistema);
    }
    
  


    char nome[] = ("arquivo_teste/teste100000.txt");


   
    ler(nome);
    //Primeira funçao vai ser ler um arquivo;
    //inserir_tempo();

    int num = 10;
    cria_lista_processo(num);

    system("pause");
    return 0;
}
