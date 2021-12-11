#include "../Libs/Processo.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    Processos pid;
    int celula_anterior;
    int celula_proxima;
}Celula;

typedef struct{
    Celula *vetor_celulas;
}lista_Processos;

Celula* criar_vetor_celula(int numero_celula);