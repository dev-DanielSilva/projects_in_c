#include <stdio.h>
#include <stdlib.h>

float valores[10], valor, maior, menor;
char txt[30];

int main()
{
    int i;

    for (i = 0; i < 10; i++){
        fflush(stdin);
        fgets(txt, sizeof(txt), stdin);
        if ((txt[0] < '0' || txt[0] > '9') && !(txt[0] == '-' && txt[1] >= '0' && txt[1] <= '9')) {
            printf("Nao e numero\n"); i=i-1; continue;
        }
        valor = atof(txt);
        valores[i] = valor;
        if (i == 0){
            maior = valor;
            menor = valor;
        }
        if (valor > maior){
            maior = valor;
        }
        else if (valor < menor){
            menor = valor;
        }
    }
    printf("%.2f\n", menor);
    printf("%.2f\n", maior);
}
