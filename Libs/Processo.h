#include <stdio.h>
#include <stdlib.h>
#include "tempo.h"
typedef struct
{
    int PID;
    tempo time;
    int Prioridade;
} Processos; 


void implementar(Processos *Processo, int PID, int hora,int min, int seg, int Prioridade);


/*
---------Alocar o processor-----------------
PID: Aleatorio
Prioridade: Aleatorio(1 a 5);
hora: Não tenho ideia de como fazer ainda
*/

//PID:
void set_PID(Processos *Processo);
int get_PID(Processos *Processo);

//Prioridade:

void set_Prioridade(Processos *Processo);
int get_Prioridade(Processos *Processo);

