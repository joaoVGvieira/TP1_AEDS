#include <stdio.h>
#include <stdlib.h>
// Criação/manipulação de um vetor dinamicamente alocado.
typedef struct{
  int idade;
  double salario;
  }TRegistro;
int main(){
  TRegistro *p;
  
  p = (TRegistro*)malloc(5*sizeof(TRegistro));
  p[0].idade = 18;
  p[0].salario = 100.0;

  printf("%d %.2lf\n", p[0].idade, p[0].salario);
  return 0;
  }