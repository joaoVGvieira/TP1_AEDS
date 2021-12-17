#include "../Libs/Processo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void hora_Atual(Processos *processo){
    struct tm *Hora_Atual;
    time_t segundos;
    time(&segundos);
    Hora_Atual= localtime(&segundos);
    processo->temp.hora = Hora_Atual->tm_hour;
    processo->temp.min = Hora_Atual->tm_min;
    processo->temp.seg = Hora_Atual->tm_sec;
}

void implementar_processo(Processos *Processo){
    set_PID(Processo);
    hora_Atual(Processo);
    set_Prioridade(Processo);
    imprimir_tempo(Processo);
}
// Abaixo estou usando rand() % 9999 para gerar um PID aleatorio de 0 ate 9999.
void set_PID(Processos *Processo){
     Processo->PID = rand() % 9999;
}
int get_PID(Processos *Proceso){
    return Proceso->PID;
}

// Funcao abaixo limita o cunjuto entre [1,5];
void set_Prioridade(Processos *Processo){
    Processo->Prioridade= 1 + rand() % 5;
}

int get_Prioridade(Processos *Proceso){
    return Proceso->Prioridade;
}

void imprimir_tempo(Processos *Processo){
    printf("Tempo--> %.2d:%.2d:%.2d\n",Processo->temp.hora, Processo->temp.min, Processo->temp.seg);
}
