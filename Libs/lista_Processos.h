#include "../Libs/Processo.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    //Processos pid;
    int celula_anterior;
    int celula_proxima;
}Vetor_Celula;

void cria_lista_processo(int numero_celulas);
void criar_vetor_celula(Vetor_Celula **celula, int numero_celulas);

void set_preenche(Vetor_Celula **celula, int numero_celulas);

int get_inprime(Vetor_Celula **celula, int numero_celulas);
