#include <stdio.h>
#include <stdlib.h>
// Criação/manipulação de um vetor dinamicamente alocado.
// Funciona
typedef struct{
  int idade;
  double salario;
  }TRegistro;

void aloca(TRegistro **p, int n){
  (*p) = (TRegistro*)malloc(n * sizeof(TRegistro));
  }
void inprime(TRegistro **p, int num){
    int i;
    for(i = 0; i < num; i++){
      printf("Idade %d    salario %.2lf\n", (*p)[i].idade, (*p)[i].salario);
    }
}
void preeenche(TRegistro **p,int num){
    int i;
    for(i = 0; i < num; i++){
      (*p)[i].idade = i;
      (*p)[i].salario = 2 * i;
    }
} 
int main(){
  TRegistro *p;
  aloca(&p,10);
  preeenche(&p, 10);
  inprime(&p,10);
  return 0;
  system("pause");
  }