#include <stdio.h>
#include <string.h>
#include  "ContaBancaria.h"

void cadastro(ContaBancaria  *Conta, int numero, float saldo, char *nome, char *cpf, char *tipoconta, int ano){
    set_numero(Conta,numero);
    set_saldo(Conta,saldo);
    Conta->cliete = Criar_cliente(nome, cpf);
    set_tipoconta(Conta,tipoconta);
    set_ano(Conta,ano);
}

void imprimir(ContaBancaria *Conta){
    imprimir_clientes(&Conta->cliete);
    printf("Conta:\n");
    printf("\n---Numero:%d---\n",get_numero(Conta));
    printf("\n---Saldo:%f---\n",get_saldo(Conta));
    printf("\n---Tipo:%s---\n",get_tipoconta(Conta));
    printf("\n---Ano de Criacao da conta:%d---\n",get_ano(Conta));
}

void depositar(ContaBancaria *Conta, float deposito){
    Conta->saldo += deposito;
}
void saque(ContaBancaria *Conta, float saque){
    if (saque >Conta->saldo ) {
        printf("Sem Saldo suficiente\n\n");
    }
    else{
        Conta->saldo -= saque;
        printf("Saque realizado com sucesso!!!\n\n");
    }

}

void avalia_conta(ContaBancaria *Conta){
    if ((2021-(Conta->ano))<=5){
        printf("Nao Habito para Emprestimo!!!\n\n");
    }
    else {
        printf("Habito para Emprestimo!!!\n\n");
    }
}

// Set serve para declarar a variavel
void set_numero(ContaBancaria *Conta, int numero_novo){
   Conta->numero= numero_novo;
}
// get serve quando vai imprimir
int get_numero(ContaBancaria *Conta){
    return Conta->numero;
}

void set_saldo(ContaBancaria *Conta, float saldo_novo){
    Conta->saldo= saldo_novo;
}

float get_saldo(ContaBancaria *Conta){
    return Conta->saldo;
}

void set_tipoconta(ContaBancaria *Conta, char *tipoconta_novo){
    strcpy(Conta->tipoconta, tipoconta_novo);
}

char* get_tipoconta(ContaBancaria *Conta){
    return Conta->tipoconta;
}




void set_ano(ContaBancaria *Conta, int ano_novo){
    Conta->ano= ano_novo;
}

int get_ano(ContaBancaria *Conta){
    return Conta->ano;
}