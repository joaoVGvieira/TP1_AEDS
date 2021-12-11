#include "../Libs/lista_Processos.h"
#include <stdio.h>
#include <stdlib.h>

int* set_criar_lista_processo(lista_Processos lista_processo, int numero_celulas){
    lista_processo = (lista_Processos*) malloc(numero_celulas * sizeof(lista_Processos));
    return lista_processo;
}
