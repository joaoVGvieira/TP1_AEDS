#include "../Libs/lista_Processos.h"
#include <stdio.h>
#include <stdlib.h>

void cria_lista_processo(int numero_celulas){
    Vetor_Celula *vetor_celula;
    criar_vetor_celula(&vetor_celula, numero_celulas);
    set_preenche(vetor_celula, numero_celulas);
    get_inprime(vetor_celula, numero_celulas);
}

void criar_vetor_celula(Vetor_Celula **celula, int numero_celulas){
    (*celula) = (Vetor_Celula*) malloc(numero_celulas * sizeof(Vetor_Celula));
}

void set_preenche(Vetor_Celula *celula, int numero_celulas){
    int i;
    for(i = 0; i < numero_celulas; i++){
        celula[i].celula_anterior = i;
        celula[i].celula_proxima = 10 * i;
        set_PID(&(celula[i].pid));
    }
}

int get_inprime(Vetor_Celula *celula, int numero_celulas){
    int i;
    for(i = 0; i < numero_celulas; i++){
        printf("Anterior: %d  //  Proximo: %d\n", celula[i].celula_anterior, celula[i].celula_proxima);
        printf("PID: %d\n", get_PID((celula[i].pid)));
    }
}
