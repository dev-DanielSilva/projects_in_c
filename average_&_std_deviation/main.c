#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float valores[10], valor, media, desvio, variancia, soma_quadrados;
float soma = 0;
char txt[30];

int main()
{
    int i;

    for (i = 0; i < 10; i++){
        fflush(stdin);
        fgets(txt, sizeof(txt), stdin);
        if (txt[0] < '0' || txt[0] > '9') {
            printf("Nao e numero\n"); i=i-1; continue;
        }
        valor = atof(txt);
        valores[i] = valor;
        soma += valores[i];
        soma_quadrados += valores[i] * valores[i];
    }

    media = soma / 10;
    variancia = (soma_quadrados / 10) - (media * media);
    desvio = sqrt(variancia);

    printf("%.2f\n", media);
    printf("%.2f\n", desvio);
}
