#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char nome[100];
    char cpf[15];
}Clientes;

Clientes Criar_cliente(char *nome, char *cpf);

void  imprimir_clientes(Clientes *cliente); 
/*
 Set: serve para alocar alguma variavel
 Get: Serve para pegar o valor da variavel normalmente usado para imprimir
 */
void set_nome(Clientes *cliente, char *nome);

char* get_nome(Clientes *cliente);

void set_cpf(Clientes *cliente, char *cpf);

char* get_cpf(Clientes *cliente);
