#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct 
{
    int hora;
    int min;
    int seg;
}tempo;

typedef struct
{
    int PID;
    tempo temp;
    int Prioridade;
} Processos; 

//Adiciona hora no struct tempo;
void hora_Atual(Processos *Processo);

void implementar_processo(Processos *Processo);

//PID:
void set_PID(Processos *Processo);
int get_PID(Processos *Processo);

//Prioridade:

void set_Prioridade(Processos *Processo);
int get_Prioridade(Processos Processo);

