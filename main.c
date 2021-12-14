#include <stdio.h>
#include <stdlib.h>
#include "Libs/lista_Processos.h"
#include "Libs/arquivos.h"

int main(void){


    char nome[] = ("arquivo_teste/teste100000.txt");

    ler(nome);
    //Primeira funçao vai ser ler um arquivo;
    //inserir_tempo();

    int num = 10;
    cria_lista_processo(num);

    system("pause");
    return 0;
}
