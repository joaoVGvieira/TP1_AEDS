#include "../Libs/lista_Processos.h"
#include <stdio.h>
#include <stdlib.h>

void cria_alocacao(Celulas **celulas, int numero_celula){
    *celulas = (Celulas*) malloc(numero_celula * sizeof(Celulas));
}
