#include "../Libs/lista_Processos.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
void inicializa_vetor(int total_celulas){
    Vetor_Celula *vetor_celula;
    Lista_Processo lista_processo;
    criar_vetor_celula(&vetor_celula, total_celulas);
    organizacao_vetor(vetor_celula, &lista_processo, total_celulas);
    //srand((unsigned)time(NULL)); // Precissa estar na nossa main para funcionar corretamente
    preenche_vetor(vetor_celula, &lista_processo, total_celulas);
    imprime_vetor(vetor_celula,&lista_processo, total_celulas);
}
*/


void criar_vetor_celula(Vetor_Celula **celula, int total_celulas){
    (*celula) = (Vetor_Celula*) malloc(total_celulas * sizeof(Vetor_Celula));
}
void organizacao_vetor(Vetor_Celula *celula, Lista_Processo *lista_processo, int total_celulas){
    int i;
    for(i = 0; i < total_celulas; i++){
        if (i == total_celulas - 1){
            set_celula_anterior(&(celula[i]), -1);
            set_celula_proxima(&(celula[i]), -1);
            lista_processo->total_celulas = total_celulas; 
            lista_processo->quantidade_celulas_ocupadas = 0;
            lista_processo->celula_disponivel = 0;
        }
        else{
            set_celula_anterior(&(celula[i]), -1);
            set_celula_proxima(&(celula[i]), i + 1);
        }
    }
}
void preenche_vetor(Vetor_Celula *celula, Lista_Processo *lista_processo, int qtd_operacao){
    int i;
    for(i = 0; i < qtd_operacao; i++){
        int aux = (lista_processo->celula_disponivel);
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
            int posi_menor_pid = lista_processo->posicao_menor_pid;
            int posi_maior_pid = lista_processo->posicao_maior_pid;
            int menor_pid, maior_pid, pid_atual;
            pid_atual = get_PID(&(celula[aux].processo));
            menor_pid = get_PID(&(celula[posi_menor_pid].processo));
            maior_pid = get_PID(&(celula[posi_maior_pid].processo));

            if (pid_atual >= maior_pid){
                set_celula_anterior(&(celula[aux]), posi_maior_pid);
                lista_processo->celula_disponivel = celula[aux].celula_proxima;
                set_celula_proxima(&(celula[aux]), -1);
                set_celula_proxima(&(celula[posi_maior_pid]), aux);
                lista_processo->posicao_maior_pid = aux;
                lista_processo->quantidade_celulas_ocupadas ++;
            }
            else if (pid_atual <= menor_pid){
                lista_processo->celula_disponivel = celula[aux].celula_proxima;
                set_celula_proxima(&(celula[aux]), posi_menor_pid);
                set_celula_anterior(&(celula[posi_menor_pid]), aux);
                lista_processo->posicao_menor_pid = aux;
                lista_processo->quantidade_celulas_ocupadas ++;
            }
            else if (menor_pid < pid_atual < maior_pid){
                int pid_comparacao = get_PID(&(celula[posi_menor_pid].processo));
                int posi_pid_comparacao = lista_processo->posicao_menor_pid;
                while (pid_comparacao <= pid_atual){
                    pid_comparacao = get_PID(&(celula[celula[posi_pid_comparacao].celula_proxima].processo));
                    posi_pid_comparacao = celula[posi_pid_comparacao].celula_proxima;
                    if(pid_comparacao > pid_atual){
                        lista_processo->celula_disponivel = celula[aux].celula_proxima;
                        set_celula_proxima(&(celula[aux]), posi_pid_comparacao);
                        set_celula_anterior(&(celula[aux]), celula[posi_pid_comparacao].celula_anterior); 
                        set_celula_proxima(&(celula[celula[posi_pid_comparacao].celula_anterior]), aux);
                        set_celula_anterior(&(celula[posi_pid_comparacao]), aux); 
                        lista_processo->quantidade_celulas_ocupadas ++;
                    }
                }
            
            }
        }
        if(lista_processo->quantidade_celulas_ocupadas == lista_processo->total_celulas){
            break;
        }
    }
}

void retirar_menor_pid(Vetor_Celula *celula, Lista_Processo *lista_processo, int qtd_operacao){
    int i;
    int posi_menor_pid = lista_processo->posicao_menor_pid;
    for(i = 0; i < qtd_operacao; i++){
        if(lista_processo->quantidade_celulas_ocupadas == 0){
            break;
        }
        lista_processo->posicao_menor_pid = celula[posi_menor_pid].celula_proxima;
        set_celula_anterior(&(celula[celula[posi_menor_pid].celula_proxima]), -1);
        set_celula_proxima(&(celula[posi_menor_pid]), lista_processo->celula_disponivel);
        lista_processo->celula_disponivel = posi_menor_pid;
        lista_processo->quantidade_celulas_ocupadas--;
        posi_menor_pid = lista_processo->posicao_menor_pid;
    }
}

void set_celula_anterior(Vetor_Celula *celula, int posicao){
    celula->celula_anterior = posicao;
}

int get_celula_anterior(Vetor_Celula *celula){
    return celula->celula_anterior;
}

void set_celula_proxima(Vetor_Celula *celula, int posicao){
    celula->celula_proxima = posicao;
}

int get_celula_proxima(Vetor_Celula *celula){
    return celula->celula_proxima;
}

int imprime_vetor(Vetor_Celula *celula, Lista_Processo *lista_processo, int numero_celulas){
    int i;
    int posicao_pid = lista_processo->posicao_menor_pid;
    printf("\nPosi_menor: %d\n", lista_processo->posicao_menor_pid);
    printf("Posi_maior: %d\n", lista_processo->posicao_maior_pid);
    printf("QTD: %d\n", lista_processo->quantidade_celulas_ocupadas);
    printf("TOTAL CELULAS: %d\n\n", lista_processo->total_celulas);
    for(i = 0; i < numero_celulas; i++){
        if (posicao_pid == -1){
            break;
        }
            printf("%.3d -> ", posicao_pid);
            printf("%d\n", get_PID(&(celula[posicao_pid].processo)));
            posicao_pid = celula[posicao_pid].celula_proxima;
    }
}
/* Serve para testar se esta organizando os elementos 
int main(){
    int a = 1000;
    srand((unsigned)time(NULL)); // Precissa estar na nossa main para funcionar corretamente
    inicializa_vetor(a);
    printf("\n");
    system("pause");
    return 0;
} */

/*int imprime_vetor(Vetor_Celula *celula, Lista_Processo *lista_processo, int numero_celulas){
    int i;
    for(i = 0; i < numero_celulas; i++){
       printf("PID: %d\n", get_PID(&(celula)))

       imprimir_tempo((celula[i].processo.time));

        //printf("Hora: ");

    }
    //imprimir_hora_arquivo(&(celula->processo.time));
}*/

