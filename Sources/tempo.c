//sem uso ainda
#include "../Libs/tempo.h"
#include <stdio.h>
#include <time.h>

void inserir_tempo(tempo temp){
   nao_sei_o_nome(&temp);
   imprimir_tempo(temp);
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
    imprimir_hora_arquivo(temp);
  
}
//achei do jeito que fiz a funçao acima meio feio, entao se acharem um jeito melhor podem mudar.*/

//hora
void set_hora(tempo *temp, int hour){
        temp->hora = hour;
}

int get_hora(tempo temp){ 
  return temp.hora;
}

//min
void set_min(tempo *temp, int min){
    temp->min = min;
}

int get_min(tempo temp){
  return temp.min;
}

//segundos
void set_seg(tempo *temp, int sec){
    temp->seg = sec;
}

int get_seg(tempo temp){
  return temp.seg;
}

// imprimir o tempo
void imprimir_tempo(tempo temp){
   printf("Tempo do sistema --> %.2d:%.2d:%.2d\n\n",get_hora(temp),get_min(temp),get_seg(temp));
}


//depois pensar como passasr essa funçao abaixo para mani_arquivo.h e mani_arquivo.c
void imprimir_hora_arquivo(tempo *temp){
  FILE *impressao = NULL;
    char shora[4], sminuto[4], ssegundo[4];

    sprintf(shora, "%.2d", temp->hora);
    sprintf(sminuto, "%.2d", temp->min);
    sprintf(ssegundo, "%.2d", temp->seg);
    impressao = fopen("Impressão.txt", "a");
    if(impressao == NULL){
        printf("Erro na abertura de impressão!\n\n");
        system("pause");
        exit(1);
    }

    fputs(shora, impressao);
    fputs(":", impressao);
    fputs(sminuto, impressao);
    fputs(":", impressao);
    fputs(ssegundo, impressao);
    fputc('\n', impressao);
    fclose(impressao);
}
// Apagar essa main quando for rodar com a main principal
int main()
{
  tempo temp;
  inserir_tempo(temp);
  return 0;
}
