//sem uso ainda
#include "../Libs/tempo.h"
#include <stdio.h>
#include <time.h>

tempo inserir_tempo(){
   tempo temp; 
   nao_sei_o_nome(&temp);
   imprimir_tempo(&temp);
   return temp;
}



int nao_sei_o_nome(tempo *temp){
    time_t currentTime;
    struct tm *timeinfo;
    currentTime= time(NULL);
    timeinfo = localtime(&currentTime);
    set_hora(temp,timeinfo->tm_hour);
    set_min(temp,timeinfo->tm_min);
    set_seg(temp,timeinfo->tm_sec);
}
//achei do jeito que fiz a funçao acima meio feio, entao se acharem um jeito melhor podem mudar.*/

//hora
void set_hora(tempo *temp, int hour){
        temp->hora = hour;
}

int* get_hora(tempo *temp){
  
  return temp->hora;
}

//min
void set_min(tempo *temp, int min){
    temp->min = min;
}

int* get_min(tempo *temp){
  return temp->min;
}

//segundos
void set_seg(tempo *temp, int sec){
    temp->seg = sec;
}

int* get_seg(tempo *temp){
  return temp->seg;
}

// imprimir o tempo
void imprimir_tempo(tempo* temp){
   printf("%d:%d:%d\n\n",get_hora(temp),get_min(temp),get_seg(temp));
}

//executem para ver funcionar
int main(){
    inserir_tempo();
}