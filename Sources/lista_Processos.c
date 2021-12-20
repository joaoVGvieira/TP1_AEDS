#include "../Libs/lista_Processos.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Aloca memória dinamicamente para um vetor de tamanho N
void criar_vetor_celula(Vetor_Celula **celula, int total_celulas){
    (*celula) = (Vetor_Celula*) malloc(total_celulas * sizeof(Vetor_Celula));
}

//Coloca -1 no campo anterior de todas as celulas e faz o encadeamento de toas as celulas
void organizacao_vetor(Lista_Processo *lista_processo, int total_celulas){
    int i;
    for(i = 0; i < total_celulas; i++){
        // Quando for a ultima posição do vetor faz isso, para o campo proximo da última posiçaõ receber -1
        if (i == total_celulas - 1){
            set_celula_anterior(&(lista_processo->celula[i]), -1);
            set_celula_proxima(&(lista_processo->celula[i]), -1);
            lista_processo->total_celulas = total_celulas; 
            lista_processo->quantidade_celulas_ocupadas = 0;
            lista_processo->celula_disponivel = 0; // Para o vetor começar a ser preenchido na posição zero
        }
        // Em todas as posiçoes do vetor exceto a última faz isso, para o vetor ficar encadeado pelos cursores
        else{
            set_celula_anterior(&(lista_processo->celula[i]), -1);
            set_celula_proxima(&(lista_processo->celula[i]), i + 1);
        }
    }
}

//Código que vai fazer as inserções, deixando os pid ordenados do menor para o maior, através de cursores
void preenche_vetor(Lista_Processo *lista_processo, int qtd_operacao){
    int i;
    for(i = 0; i < qtd_operacao; i++){
        // aux foi usado para representar a celula disponivel, para deixar o código mais compacto
        int aux = (lista_processo->celula_disponivel);
        // Quando a lista estiver vazia e executado esse if, para que a posição de maior e menor pid receba este primeiro número
        if(lista_processo->quantidade_celulas_ocupadas == 0){
            implementar_processo(&(lista_processo->celula[aux].processo)); // Quando é chamada, chama outras 3 funções que geram por sua vez o pid, a prioridade e pega a hora atual
            lista_processo->posicao_maior_pid = aux;
            lista_processo->posicao_menor_pid = aux;
            lista_processo->celula_disponivel = lista_processo->celula[aux].celula_proxima;
            set_celula_proxima(&(lista_processo->celula[aux]), -1);
            lista_processo->quantidade_celulas_ocupadas ++; 
        }
        // Quando houver algum pid na lista e exutado este código
        else{
            implementar_processo(&(lista_processo->celula[aux].processo));
            // As proximas 6 linhas servem para o fim de simplificar o código posteriormrntr 
            int posi_menor_pid = lista_processo->posicao_menor_pid;
            int posi_maior_pid = lista_processo->posicao_maior_pid;
            int menor_pid, maior_pid, pid_atual;
            pid_atual = get_PID(&(lista_processo->celula[aux].processo));
            menor_pid = get_PID(&(lista_processo->celula[posi_menor_pid].processo));
            maior_pid = get_PID(&(lista_processo->celula[posi_maior_pid].processo));

            // Este if e executando quando é gerado um pid maior do que o maior pid existemte, 
            // por sua vez esse novo pid se torna o maior pid do vetor
            if (pid_atual >= maior_pid){
                set_celula_anterior(&(lista_processo->celula[aux]), posi_maior_pid);
                lista_processo->celula_disponivel = lista_processo->celula[aux].celula_proxima;
                set_celula_proxima(&(lista_processo->celula[aux]), -1);
                set_celula_proxima(&(lista_processo->celula[posi_maior_pid]), aux);
                lista_processo->posicao_maior_pid = aux;
                lista_processo->quantidade_celulas_ocupadas ++;
            }

            // Este else if e executando quando é gerado um pid mnor do que o menor pid existemte, 
            // por sua vez esse novo pid se torna o menor pid do vetor
            else if (pid_atual <= menor_pid){
                lista_processo->celula_disponivel = lista_processo->celula[aux].celula_proxima;
                set_celula_proxima(&(lista_processo->celula[aux]), posi_menor_pid);
                set_celula_anterior(&(lista_processo->celula[posi_menor_pid]), aux);
                lista_processo->posicao_menor_pid = aux;
                lista_processo->quantidade_celulas_ocupadas ++;
            }

            //Este else if e executado quando e gerado um pid que não e o menor nem o maior, 
            // que será colocado no 'meio' do vetor. Este novo pid será colocado atrás do primeiro pid maior que ele
            else if (menor_pid < pid_atual < maior_pid){
                int pid_comparacao = get_PID(&(lista_processo->celula[posi_menor_pid].processo));
                int posi_pid_comparacao = lista_processo->posicao_menor_pid;
                while (pid_comparacao <= pid_atual){
                    pid_comparacao = get_PID(&(lista_processo->celula[lista_processo->celula[posi_pid_comparacao].celula_proxima].processo));
                    posi_pid_comparacao = lista_processo->celula[posi_pid_comparacao].celula_proxima;
                    if(pid_comparacao > pid_atual){
                        lista_processo->celula_disponivel = lista_processo->celula[aux].celula_proxima;
                        set_celula_proxima(&(lista_processo->celula[aux]), posi_pid_comparacao);
                        set_celula_anterior(&(lista_processo->celula[aux]), lista_processo->celula[posi_pid_comparacao].celula_anterior); 
                        set_celula_proxima(&(lista_processo->celula[lista_processo->celula[posi_pid_comparacao].celula_anterior]), aux);
                        set_celula_anterior(&(lista_processo->celula[posi_pid_comparacao]), aux); 
                        lista_processo->quantidade_celulas_ocupadas ++;
                    }
                }
            
            }
        }
        // Este if serve para verificar se o vetor encheu, quando ele enche da um break e para de inserir novos pid
        if(lista_processo->quantidade_celulas_ocupadas == lista_processo->total_celulas){
            printf("ATENCAO !!! VETOR CHEIO. NAO E POSSIVEL ADICIONAR ELEMENTOS!!!");
            break;
        }
    }
}

// Função responsavel por retirar os N menore pids. N este passado pelo usúario ou arquivo
void retirar_menor_pid(Lista_Processo *lista_processo, int qtd_operacao){
    int i;
    int posi_menor_pid = lista_processo->posicao_menor_pid;
    for(i = 0; i < qtd_operacao; i++){
        // Este if e responsavel por verificar quando o vetor esta/ficou vazio
        if(lista_processo->quantidade_celulas_ocupadas == 0){
            printf("\n ATENCAO!!!! LISTA VAZIA. NAO E POSSIVEL RETIRAR ELEMENTOS!!!\n");
            break;
        }

        lista_processo->posicao_menor_pid = lista_processo->celula[posi_menor_pid].celula_proxima;
        set_celula_anterior(&(lista_processo->celula[lista_processo->celula[posi_menor_pid].celula_proxima]), -1);
        set_celula_proxima(&(lista_processo->celula[posi_menor_pid]), lista_processo->celula_disponivel);
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

// Função que retorna o total de celulas ocuadas do vetor
int get_total_celulas_ocupadads(Lista_Processo lista_processo){
    return lista_processo.quantidade_celulas_ocupadas;
}

// Função que liberá a memória alocada dinamicamente
void libera_memoria(Vetor_Celula **celula){
    free(*celula);
}

// Função que imprime os dados armazenados no vetor, ordenados de acordo com o pid
int imprime_vetor(Lista_Processo *lista_processo, int numero_celulas){
    int i;
    int posicao_pid = lista_processo->posicao_menor_pid;
    for(i = 0; i < numero_celulas; i++){
        if (posicao_pid == -1){
            break;
        }
        printf("PID: %d\n", get_PID(&(lista_processo->celula[posicao_pid].processo)));
        printf("Prioridade: %d\n", get_Prioridade(&(lista_processo->celula[posicao_pid].processo)));
        imprimir_tempo(&(lista_processo->celula[posicao_pid].processo));
        printf("\n");
        posicao_pid = lista_processo->celula[posicao_pid].celula_proxima;
    }
}

