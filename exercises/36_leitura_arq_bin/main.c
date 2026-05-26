#include <stdio.h>
#include <stdlib.h>
#define nomeArq "nros.bin"
#define TOTAL 10

FILE *ArqBin;
double numeros[10];

int main()
{
    ArqBin = fopen(nomeArq, "rb");
    if (ArqBin)
    {
        fread(numeros, sizeof(double), TOTAL, ArqBin);
        fclose(ArqBin);
    }
    for (int i = 0; i < TOTAL; i++)
    {
        printf("%.2lf\n", numeros[i]);
    }

    return 0;
}
