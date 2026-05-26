#include <stdio.h>
#include <stdlib.h>
#define nomeArq "texto.txt"
#define TAM_BUFFER 100

FILE* arqIn;
char linha[100];

int main()
{
    int count = 1;
    arqIn = fopen(nomeArq, "rt");
    if(arqIn)
    {
        while(fgets(linha, TAM_BUFFER, arqIn) != NULL)
        {
            if (linha[0] != '#')
            {
                printf("%d: %s", count, linha);
                count++;
            }
        }
        fclose(arqIn);
    }
    else
    {
        printf("Erro na leitura do arquivo de entrada!");
    }
    return 0;
}
