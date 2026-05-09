#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NomeArq "texto.txt"

FILE *ArqOut;
char texto[100];
char codigo;

int main()
{
    // Abre arquivo para escrita, retorna falso se houver erro
    if (ArqOut=fopen(NomeArq,"wt")){
        codigo = ' ';
    // Loop de captura, para se houver '#'
        while (codigo != '#'){
            fgets(texto, sizeof(texto), stdin);
            fprintf(ArqOut, "%s\n", texto);
            codigo = texto[0];
        }
        fclose(ArqOut);
    }
    else {
        printf("Erro na criacao do arquivo de saida!");
    }
    return(0);
}
