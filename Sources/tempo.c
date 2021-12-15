//sem uso ainda
#include "../Libs/tempo.h"
#include <stdio.h>
#include <time.h>

/*void inserir_tempo(tempo temp){
   armazenar_a_hora(&temp);
   imprimir_tempo(temp);
} */



void armazenar_a_hora(tempo *temp){
    time_t currentTime;
    struct tm *timeinfo;
    currentTime= time(NULL);
    timeinfo = localtime(&currentTime);
    set_hora(temp,timeinfo->tm_hour);
    set_min(temp,timeinfo->tm_min);
    set_seg(temp,timeinfo->tm_sec);
}

void tempo_final(tempofi *temp){
    int a;
    printf("Digit A;");
    scanf("%d",&a);
    time_t currentTime;
    struct tm *timeinfo;
    currentTime= time(NULL);
    timeinfo = localtime(&currentTime);
    set_horafi(temp,timeinfo->tm_hour);
    set_minfi(temp,timeinfo->tm_min);
    set_segfi(temp,timeinfo->tm_sec);
}
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
void imprimir_hora_arquivo(tempo *temp, tempofi *tempofi){
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

//hora
void set_horafi(tempofi *temp, int hour){
        temp->hora = hour;
}

int get_horafi(tempofi temp){ 
  return temp.hora;
}

//min
void set_minfi(tempofi *temp, int min){
    temp->min = min;
}

int get_minfi(tempofi temp){
  return temp.min;
}

//segundos
void set_segfi(tempofi *temp, int sec){
    temp->seg = sec;
}

int get_segfi(tempofi temp){
  return temp.seg;
}
/*
int main(){
  tempo temp;
  tempofi tempi;
  armazenar_a_hora(&temp);
  tempo_final(&tempi);
  imprimir_tempo(temp);
  imprimir_final_tempo(tempi);


}*/