#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nomeArq "salvo.txt"
#define TAM_BUFFER 100

char texto[TAM_BUFFER + 5];
char palavra[] = "FIM";
FILE *ArqIn;

int main()
{
    ArqIn = fopen(nomeArq, "wt");
    if (ArqIn)
    {
        for( ; ; )
        {
            fgets(texto, TAM_BUFFER, stdin);
            fputs(texto, ArqIn);
            if (strncmp(texto, palavra, 3) == 0){
                break;
            }
        }
        fclose(ArqIn);
    }
    system("cat salvo.txt"); //COMANDO TYPE AO INVÉS DE CAT NO WINDOWS
    return 0;
}
