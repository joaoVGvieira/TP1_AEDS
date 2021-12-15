#include "../Libs/lista_Processos.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void inicializa_vetor(int total_celulas){
    Vetor_Celula *vetor_celula;
    criar_vetor_celula(&vetor_celula, total_celulas);
    organizacao_vetor(vetor_celula, total_celulas);
    set_preenche(vetor_celula, total_celulas);
    get_inprime(vetor_celula, total_celulas);
}

void criar_vetor_celula(Vetor_Celula **celula, int total_celulas){
    (*celula) = (Vetor_Celula*) malloc(total_celulas * sizeof(Vetor_Celula));
}

void organizacao_vetor(Vetor_Celula *celula, int total_celulas){
    int i;
    for(i = 0; i < total_celulas; i++){
        if (i == total_celulas - 1){
            set_celula_anterior(&(celula[i]), -1);
            set_celula_proxima(&(celula[i]), -1);
            Lista_Processo *lista_processo;
            lista_processo->total_celulas = total_celulas;
            lista_processo->quantidade_celulas_ocupadas = 0;
            lista_processo->celula_disponivel = 0;
        }
        set_celula_anterior(&(celula[i]), -1);
        set_celula_proxima(&(celula[i]), i + 1);
    }
}
void preenche_vetor(Vetor_Celula *celula, int qtd_operacao){
    Lista_Processo *lista_processo;
    int i;
    for(i = 0; i < qtd_operacao; i++){
        srand((unsigned)time(NULL));
        int aux = lista_processo->celula_disponivel;
        if(lista_processo->quantidade_celulas_ocupadas == 0){
            implementar_processo(&(celula[aux].processo));
            lista_processo->posicao_maior_pid = aux;
            lista_processo->posicao_menor_pid = aux;
            lista_processo->celula_disponivel = celula[aux].celula_proxima;
            set_celula_proxima(&(celula[aux]), -1);
            lista_processo->quantidade_celulas_ocupadas ++;
        }
        else{
            implementar_processo(&(celula[aux].processo));
            int posi_primeiro_pid = lista_processo->posicao_menor_pid;
            int posi_ultimo_pid = lista_processo->posicao_maior_pid;
            int menor_pid, maior_pid, pid_atual;
            pid_atual = get_PID(&(celula[aux].processo));
            menor_pid = get_PID(&(celula[posi_primeiro_pid].processo));
            maior_pid = get_PID(&(celula[posi_ultimo_pid].processo));
            if (pid_atual <= menor_pid){
                set_celula_proxima(&(celula[aux]), posi_primeiro_pid);
                set_celula_anterior(&(celula[posi_primeiro_pid]), aux);
                lista_processo->posicao_menor_pid = aux;
                lista_processo->celula_disponivel = celula[aux].celula_proxima;
                lista_processo->quantidade_celulas_ocupadas ++;
            }
            else if (pid_atual >= maior_pid){
                set_celula_anterior(&(celula[aux]), posi_ultimo_pid);
                lista_processo->celula_disponivel = celula[aux].celula_proxima;
                set_celula_proxima(&(celula[aux]), -1);
                set_celula_proxima(&(celula[posi_ultimo_pid]), aux);
                lista_processo->posicao_maior_pid = aux;
                lista_processo->quantidade_celulas_ocupadas ++;
            }
            else if (menor_pid < pid_atual < maior_pid){
                int pid_comparacao = get_PID(&(celula[menor_pid].processo));
                int posi_pid_comparacao = menor_pid;
                while (pid_comparacao <= pid_atual){
                    int pid_comparacao = get_PID(&(celula[celula[posi_pid_comparacao].celula_proxima].processo));
                    int posi_pid_comparacao = celula[posi_pid_comparacao].celula_proxima;
                    if(pid_atual < pid_comparacao){
                        lista_processo->celula_disponivel = celula[aux].celula_proxima;
                        set_celula_anterior(&(celula[aux]), celula[posi_pid_comparacao].celula_anterior);
                        set_celula_proxima(&(celula[aux]), posi_pid_comparacao);
                        set_celula_anterior(&(celula[posi_pid_comparacao]), aux);
                        set_celula_proxima(&(celula[celula[posi_pid_comparacao].celula_anterior]), aux);
                        lista_processo->quantidade_celulas_ocupadas ++;
                        break;
                    }
                }
                
            }
        }
    }
}

void set_celula_anterior(Vetor_Celula *celula, int posicao){
    celula->celula_anterior = posicao;
}

//int get_celula_anterior(Vetor_Celula celula, int posicao);

void set_celula_proxima(Vetor_Celula *celula, int posicao){
    celula->celula_proxima = posicao;
}

//int get_celula_proxima(Vetor_Celula celula, int posicao);

int imprime_vetor(Vetor_Celula *celula, int numero_celulas){
    int i;
    for(i = 0; i < numero_celulas; i++){
        printf("Anterior: %d // Proximo: %d //", celula[i].celula_anterior, celula[i].celula_proxima);
        printf("PID: %d // Prioridade: %d\n", get_PID(&(celula[i].processo)), get_Prioridade((celula[i].processo)));

        imprimir_tempo((celula[i].processo.time));

        //printf("Hora: ");

    }
    imprimir_hora_arquivo(&(celula->processo.time));
}
