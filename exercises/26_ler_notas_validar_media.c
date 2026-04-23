#include <stdio.h>
#include <stdlib.h>

double notas[3], nota, media;
double soma = 0;
char txt[30];

int main()
{
    int j = 0;

    for (int i = 0; i < 3; i++){
        fflush(stdin);
        fgets(txt, sizeof(txt), stdin);
        nota = atof(txt);
        if (nota < 0 || nota > 10) {
            printf("ERRO\n");
            i = i - 1;
        } else {
            notas[i] = nota;
            soma = soma + notas[i];
        }
    }
    media = soma / 3;
    printf("%.2lf", media);
}
