#include "../Libs/lista_Processos.h"
#include <stdio.h>
#include <stdlib.h>

Celula* criar_vetor_celula(int numero_celula){
    Celula *lista_celula;
    lista_celula = (Celula*) malloc(numero_celula * sizeof(Celula));
    return lista_celula;
}