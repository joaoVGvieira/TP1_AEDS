//sem uso ainda
#include "../Libs/tempo.h"
#include <stdio.h>
#include <tempo.h>
inserir_tempo(tempo *time, int hora, int min, int seg){

}

#include <time.h>
#include <stdio.h>

int main(){
    time_t currentTime;
    struct tm *timeinfo;

    currentTime= time(NULL);

    timeinfo = localtime(&currentTime);

    printf("%02d:%02d:%02d\n\n",timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}