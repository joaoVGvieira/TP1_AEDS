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

void inicializa_vetor(int total_celulas);

void criar_vetor_celula(Vetor_Celula **celula, int total_celulas);

void preenche_vetor(Vetor_Celula *celula, Lista_Processo *lista_processo, int qtd_operacao);

void organizacao_vetor(Vetor_Celula *celula, Lista_Processo *lista_processo, int total_celulas);

int imprime_vetor(Vetor_Celula *celula, Lista_Processo *lista_processo, int numero_celulas);

void set_celula_anterior(Vetor_Celula *celula, int posicao);

int get_celula_anterior(Vetor_Celula *celula);

void set_celula_proxima(Vetor_Celula *celula, int posicao);

int get_celula_proxima(Vetor_Celula *celula);

void set_celula_disponivel(Lista_Processo *lista_processo, int celula_disponivel);

int get_celula_disponivel(Lista_Processo *lista_processo);

void set_posicao(Vetor_Celula *celula, int posicao);

int get_celula_anterior(Vetor_Celula *celula);
/*
void inicializa_vetor(int total_celulas);

void criar_vetor_celula(Vetor_Celula **celula, int total_celulas);

void preenche_vetor(Vetor_Celula *celula, int qtd_operacao);

int imprime_vetor(Vetor_Celula *celula, int numero_celulas);

void organizacao_vetor(Vetor_Celula *celula, int total_celulas);

void set_celula_anterior(Vetor_Celula *celula, int posicao);

int get_celula_anterior(Vetor_Celula celula, int posicao);

void set_celula_proxima(Vetor_Celula *celula, int posicao);

int get_celula_proxima(Vetor_Celula celula, int posicao); */
