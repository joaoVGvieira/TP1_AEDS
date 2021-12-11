#include "../Libs/Processo.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    Processos pid;
}Celulas;

typedef struct{
    Celulas *celulas;
}lista_Processos;

void cria_alocacao(Celulas **celulas, int numero_celula);
