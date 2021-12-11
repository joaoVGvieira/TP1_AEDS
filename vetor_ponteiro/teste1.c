#include <stdio.h>
#include <stdlib.h>
// Manipulação de apontamento de ponteiros.
int main(){
    double a;
    double *p;
    a = 3.14;
    printf("%lf\n", a);
    p = &a;
    printf("%lf\n", *p);
    *p = 2.78;
    printf("%lf\n", *p);
    p = (double*)malloc(sizeof(double));
    *p = 20.0;
    printf("%lf\n", *p);
    free(p);
    printf("%lf\n", *p);
    return 0;
} 