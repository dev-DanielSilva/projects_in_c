#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char txt[30];
double valores[30], qtd, num, media, soma_quadrados, desvio, variancia, maior, menor;
double soma = 0;

int main()
{
    fflush(stdin);
    fgets(txt, sizeof(txt), stdin);
    qtd = atof(txt);

    if (qtd <= 0 || qtd > 30){
        printf("Valor invalido");
    }
    else {
        int count = 0;
        while (count < qtd){
            fflush(stdin);
            fgets(txt, sizeof(txt), stdin);
            if ((txt[0] < '0' || txt[0] > '9') && txt[0] != '-'){
                printf("Nao eh numero\n");
            }
            else {
                num = atof(txt);
                valores[count] = num;
                if (count == 0){
                    maior = valores[count];
                    menor = valores[count];
                }
                else if (num > maior){
                    maior = num;
                }
                else if (num < menor){
                    menor = num;
                }

                soma += valores[count];
                soma_quadrados += valores[count] * valores[count];
                count++;
            }

        }
        media = soma / qtd;
        variancia = (soma_quadrados / qtd) - (media * media);
        desvio = sqrt(variancia);

        printf("%.2lf\n", menor);
        printf("%.2lf\n", maior);
        printf("%.2lf\n", media);
        printf("%.2lf\n", desvio);
    }


}
