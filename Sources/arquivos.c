#include "../Libs/arquivos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ler(char nome[]){
    FILE *file = fopen(nome,"r");
    if(file==NULL){
        printf("Erro para abrir o arquivo!!!!");
        exit(1);
    }
    printf("\n\nAberto com sucesso!!!!\n\n");
}

