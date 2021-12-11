//sem uso ainda
#include "../Libs/tempo.h"
#include <stdio.h>
#include <time.h>

tempo inserir_tempo(){
   tempo temp; 
   nao_o_nome(&temp);
   printf("\n\nhora:%d\n\n",temp.hora);
}

// deu certo na base da gabiarra 

int nao_o_nome(tempo *temp){
    time_t currentTime;
    struct tm *timeinfo;
    currentTime= time(NULL);
    timeinfo = localtime(&currentTime);
    temp->hora = timeinfo->tm_hour;
    temp->min = timeinfo->tm_min;
    temp->seg = timeinfo->tm_sec;
}
//achei do jeito que fiz a funçao acima meio feio, entao se acharem um jeito melhor podem mudar.*/
