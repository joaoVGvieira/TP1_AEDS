#include <stdio.h>
#include <stdlib.h>
// Mantendo o endereço salvo o endereço de um vetor dinamicamente alocado.
void aloca(int **x, int n){
  (*x) = (int*)malloc(n*sizeof(int));
  (*x)[0] = 20;
  }

int main(){
  int *a;
  aloca(&a, 5);
  a[1] = 40;
  return 0;
}