#include <stdio.h>
#include <stdlib.h>
#define nomeArq "nros.txt"
#define TAM_BUFFER 100

FILE *ArqIn;
char texto[TAM_BUFFER + 5];
float nro, media;
float soma = 0;

int main()
{
    ArqIn = fopen(nomeArq, "rt");
    int qtd = 0;
    if (ArqIn)
    {
        while(fgets(texto, TAM_BUFFER, ArqIn) != NULL)
        {
            nro = atof(texto);
            soma = soma + nro;
            printf("%.1f\n", nro);
            qtd++;
        }
        fclose(ArqIn);
        if (qtd > 0)
        {
            media = soma/qtd;
        }
        else
        {
            printf("Erro, arquivo vazio");
        }
        printf("%.2f\n", media);
    }
    else {
        printf("Erro na leitura do arquivo de entrada!");
    }
    return(0);

}
