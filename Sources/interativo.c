#include "../Libs/interativo.h"

void menu_interativo(){
    Lista_Processo lista_processo;
    int N, opcao, Qt;
    printf("DIGITE O TAMANHO N DO VETOR PARA INICIALIZA-LO: ");
    scanf("%d",&N);
    criar_vetor_celula(&(lista_processo.celula), N);
    organizacao_vetor(&lista_processo, N);

    do
    { 
        printf("\n");
        printf(  
                " _________________(MENU INTERATIVO)__________________\n"
                "|                                                    |\n"
                "| INSERIR  = 1                                       |\n"
                "| REMOVER  = 2                                       |\n"
                "| IMPRIMIR = 3                                       |\n"
                "| TOTAL CELULAS OCUPADAS = 4                         |\n"
                "| ENCERRAR OPERACOES = 0                             |\n"
                "|____________________________________________________|\n");
            printf("DIGITE A OPERACAO DESEJADA: ");
            scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            printf("\nQUANTIDADE DE INSERSOES: ");
            scanf("%d", &Qt);
            preenche_vetor(&lista_processo, Qt);
            break;
        case 2:
            printf("\nQUANTIDADE DE REMOCOES: ");
            scanf("%d", &Qt);
            retirar_menor_pid(&lista_processo, Qt);
            break;
        case 3:
            printf("\n");
            imprime_vetor(&lista_processo, N);
            break;
        case 4:
            printf("\nTotal de celulas ocupadas: %d\n", get_total_celulas_ocupadads(lista_processo));
            break;
        case 0:
            break;
        default:
            printf("\n\n-----Opcao invalida!!!!-----\n\n");  
            break;
        }
            
    } while (opcao!=0); 
}
