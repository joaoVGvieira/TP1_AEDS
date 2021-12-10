#include <stdio.h>
#include <stdlib.h>
#include "ContaBancaria.h"
#define  N 15
int main(int argc, char** argv) {

    ContaBancaria Conta;
    
    ContaBancaria *a;
    
    a = (ContaBancaria*)malloc(5*sizeof(ContaBancaria);
    int  opcao;
    float valor_deposito, valor_saque;
    while (opcao!=9) {
        printf("1.Cadastro.\n"
                "2.imprimir\n"
                "3.depositar\n"
                "4.Saque\n"
                "5.Emprestimo\n"
                "9.Sair.\n"
                "Digite:");
        scanf("%d",&opcao);
        switch(opcao){
            case 1:
                printf("--------------------CADASTRO---------------------\n\n");
                printf("Numero:");
                scanf("%d",&Conta.numero);
                printf("Valor inicial:");
                scanf("%f",&Conta.saldo);
                printf("Nome:");
                scanf("\n%[^\n]s",Conta.cliete.nome);
                printf("CPF:");
                scanf("\n%[^\n]s",Conta.cliete.cpf);
                printf("Tipo de conta:");
                scanf("\n%[^\n]s ",Conta.tipoconta);
                printf("Ano da criacao:");
                scanf("%d",&Conta.ano);
                cadastro(&Conta, Conta.numero ,Conta.saldo,Conta.cliete.nome,Conta.cliete.cpf, Conta.tipoconta,Conta.ano);
                printf("\n");
                break;
            case 2:
              
                imprimir(&Conta);
                break;
            case 3:
                   printf("--------------------DEPOSITO---------------------\n\n");
                   printf("Quanto voce quer depositar:");
                   scanf("%f",&valor_deposito);
                   depositar(&Conta, valor_deposito);
                break;
            case 4:
                   printf("--------------------SAQUE---------------------\n\n");
                   printf("Quanto voce quer sacar:");
                   scanf("%f",&valor_saque);
                   saque(&Conta, valor_saque);
                break;
            case 5:
                avalia_conta(&Conta);
                break;
            case 9:
                printf("\nVolte sempre!!!\n");
                break;
            default:
                printf("Opcao Errada!!!, Tenha atençao!!!\n\n");
        }
    }

    
}

