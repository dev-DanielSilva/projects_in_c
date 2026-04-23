#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float num, media, desvio, variancia, soma_quadrados;
float soma = 0;

int main()
{
    for (int i = 0; i < 10; i ++){
        scanf("%f", &num);
        soma += num;
        soma_quadrados += num * num;
    }
    media = soma / 10;
    variancia = (soma_quadrados / 10) - (media * media);
    desvio = sqrt(variancia);

    printf("%.2f\n", media);
    printf("%.2f\n", desvio);

    return 0;
}
