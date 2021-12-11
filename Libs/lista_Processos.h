#include "../Libs/Processo.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    Processos pid;
    int celula_anterior;
    int celula_proxima;
}Celulas;
typedef struct lista *lista_Processos;
typedef struct lista {
    Celulas celulas;
};

int* set_criar_lista_processo(lista_Processos lista_processo ,int numero_celulas);
