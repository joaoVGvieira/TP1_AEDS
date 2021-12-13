#include <stdio.h>
#include <stdlib.h>

typedef struct 
{   
    int hora;
    int min;
    int seg;
}tempofinal;


typedef struct 
{
    int hora;
    int min;
    int seg;
}tempo;


//void inserir_tempo(tempo temp);

void armazenar_a_hora(tempo *temp);

void armazenar_a_hora_final(tempofinal *temp);
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

//tempofinal

//hora
void set_horafi(tempofinal *temp, int hour);

int get_horafi(tempofinal temp);

//min
void set_minfi(tempofinal *temp, int min);

int get_minfi(tempofinal temp);


//segundos
void set_segfi(tempofinal *temp, int sec);

int get_segfi(tempofinal temp);