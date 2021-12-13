#include "../Libs/mani_arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *abrir(){
    FILE *arq = NULL;
    arq = fopen("teste.txt", "r");
    return arq;
}
void fechar(FILE *f){
    int verify = fclose(f);
    if (verify == 0){
        printf("Fechou.\n");
    }
}
/*void imprimir(hora, minuto, segundo){
    FILE *impressao = NULL;
    char shora[2], sminuto[2], ssegundo[2];
    sprintf(shora, "%d", hora);
    sprintf(sminuto, "%d", minuto);
    sprintf(ssegundo, "%d", segundo);
    impressao = fopen("Impressão.txt", "w");
    if(impressao == NULL){
        printf("Erro na abertura de impressão!");
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
}*/