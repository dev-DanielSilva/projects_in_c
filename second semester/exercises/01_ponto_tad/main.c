#include <stdio.h>
#include <stdlib.h>
#include "Ponto.h"
int main(){
    float d;
    float p1x,p1y,p2x,p2y;
    Ponto *p,*q;

    scanf("%f",&p1x);
    scanf("%f",&p1y);
    scanf("%f",&p2x);
    scanf("%f",&p2y);

    p = pto_cria(p1x,p1y);
    q = pto_cria(p2x,p2y);

    d = pto_distancia(p,q);
    printf("%.2f\n",d);

    pto_libera(q);
    pto_libera(p);

    // system("pause");
    return 0;
}