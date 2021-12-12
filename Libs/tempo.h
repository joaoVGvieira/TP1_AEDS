#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int hora;
    int min;
    int seg;
}tempo;


//tempo inserir_tempo();

int nao_sei_o_nome(tempo *temp);
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

