#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int hora;
    int min;
    int seg;
}tempofi;

typedef struct 
{   
    int hora;
    int min;
    int seg;
}tempo;


//void inserir_tempo(tempo temp);

void armazenar_a_hora(tempo *temp);

//hora
void set_hora(tempo *temp, int hour);

int get_hora(tempo temp);

//min
void set_min(tempo *temp, int min);

int get_min(tempo temp);


//segundos
void set_seg(tempo *temp, int sec);

int get_seg(tempo temp);

void imprimir_tempo(tempo temp);

void imprimir_hora_arquivo(tempo *temp);




//TEMPO FINAL


void tempo_final(tempofi *temp);

//hora
void set_horafi(tempofi *temp, int hour);

int get_horafi(tempofi temp);

//min
void set_minfi(tempofi *temp, int min);

int get_minfi(tempofi temp);


//segundos
void set_segfi(tempofi *temp, int sec);

int get_segfi(tempofi temp);

void imprimir_final_tempo(tempofi temp);