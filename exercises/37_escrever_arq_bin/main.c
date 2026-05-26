#include <stdio.h>
#include <stdlib.h>

#define nomeArq "nros1.bin"
#define TOTAL 10

int main()
{
    FILE *ArqBin;
    double nros[TOTAL];
    char txt[50];

    ArqBin = fopen(nomeArq, "wb");
    if (ArqBin)
    {
        for (int i = 0; i < TOTAL; i++)
        {
            fgets(txt, sizeof(txt), stdin);
            nros[i] = atof(txt);
            if (i == 10) break;
        }
        fwrite(nros, sizeof(double), 1, ArqBin);
        fclose(ArqBin);
    }
    else
    {
        printf("Erro ao abrir arquivo.");
    }
}
