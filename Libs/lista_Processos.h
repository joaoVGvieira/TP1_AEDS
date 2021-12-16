#include "../Libs/Processo.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    Processos processo;
    int celula_anterior;
    int celula_proxima;
}Vetor_Celula;

typedef struct{
    Vetor_Celula *celula;
    int posicao_menor_pid;
    int posicao_maior_pid;
    int celula_disponivel;
    int quantidade_celulas_ocupadas;
    int total_celulas;
}Lista_Processo;

//void inicializa_vetor(int total_celulas);

void criar_vetor_celula(Vetor_Celula **celula, int total_celulas);

void preenche_vetor(Vetor_Celula *celula, Lista_Processo *lista_processo, int qtd_operacao);

void retirar_menor_pid(Vetor_Celula *celula, Lista_Processo *lista_processo, int qtd_operacao);

void organizacao_vetor(Vetor_Celula *celula, Lista_Processo *lista_processo, int total_celulas);

int imprime_vetor(Vetor_Celula *celula, Lista_Processo *lista_processo, int numero_celulas);

void set_celula_anterior(Vetor_Celula *celula, int posicao);

int get_celula_anterior(Vetor_Celula *celula);

void set_celula_proxima(Vetor_Celula *celula, int posicao);

int get_celula_proxima(Vetor_Celula *celula);
