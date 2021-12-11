#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
Clientes Criar_cliente(char *nome, char *cpf){
    Clientes cliente;
    set_nome(&cliente,nome);
    set_cpf(&cliente,cpf);
    return cliente;
}

void imprimir_clientes(Clientes* cliente){
    printf("Cliente:\n");
    printf("\n---Nome:%s---\n",get_nome(cliente));
    printf("\n---CPF:%s---\n\n",get_cpf(cliente));
}



void set_nome(Clientes *cliente, char *nome_novo){
    strcpy(cliente->nome, nome_novo);
}

char* get_nome(Clientes *cliente){
    return cliente->nome;
}



void set_cpf(Clientes *cliente, char *cpf_novo){
     strcpy(cliente->cpf, cpf_novo);
}

char* get_cpf(Clientes *cliente){
    return cliente->cpf;
}