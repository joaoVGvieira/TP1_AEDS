// Tem que fazer funcionar, pelo geito que eu imaginei Iury
#include <stdio.h>
#include <stdlib.h>
// Criação/manipulação de um vetor dinamicamente alocado.
void aloca(TRegistro **p, int n){
  //TRegistro *p;
  p = (TRegistro*)malloc(n * sizeof(TRegistro));
  }
void inprime(int num){
    TRegistro *p;
    int i;
    for(i = 0; i < num; i++){
      printf("Idade %d    salario %.2lf\n");
    }
}
void preeenche(int num){
    TRegistro *p;
    int i;
    for(i = 0; i < num; i++){
      p[i].idade = i;
      p[i].salario = 2 * 1;
    }
}
typedef struct{
  int idade;
  double salario;
  }TRegistro;

int main(){
  TRegistro *p;
  aloca(&p,10);
  inprime(10);
  preeenche(10);
  return 0;
  }