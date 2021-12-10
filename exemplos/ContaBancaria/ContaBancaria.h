#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
typedef struct{
    int numero;
    float saldo;
    Clientes cliete;
    char tipoconta[100];
    int ano;
}ContaBancaria;

void cadastro(ContaBancaria *Conta, int numero, float saldo, char *nome, char *cpf, char *tipoconta, int ano);
void imprimir(ContaBancaria *Conta);
void depositar(ContaBancaria *Conta, float deposito);
void saque(ContaBancaria *Conta, float saque);
void avalia_conta(ContaBancaria *Conta);


void set_numero(ContaBancaria *Conta, int numero_novo);
int get_numero(ContaBancaria *Conta);

void set_saldo(ContaBancaria *Conta, float saldo_novo);
float get_saldo(ContaBancaria *Conta);

/*void set_nome(ContaBancaria *Conta, char *nome_novo);
char* get_nome(ContaBancaria *Conta);

void set_cpf(ContaBancaria *Conta, char *cpf_novo);
char* get_cpf(ContaBancaria *Conta);
*/
void set_tipoconta(ContaBancaria *Conta, char *tipoconta_novo);
char* get_tipoconta(ContaBancaria *Conta);

void set_ano(ContaBancaria *Conta, int ano_novo);
int get_ano(ContaBancaria *Conta);
