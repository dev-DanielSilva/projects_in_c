#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 53 // Máximo de 50 caracteres + espaços para '\0', '\r' e '\n'

char txt[MAX];
int n;

int main()
{
    fgets(txt, sizeof(txt), stdin);
    // Converte a string lida do teclado para o número inteiro correspondente
    n = atoi(txt);

    // Valida se o número de palavras é maior que zero
    if(n <= 0) {
        return -1;
    }

    // Aloca dinamicamente o array de ponteiros (as "linhas" da matriz)
    char **palavras = calloc(n, sizeof(char *));

    // Aloca memória para cada string e realiza a leitura dos dados
    for (int i = 0; i < n; i ++){
        // Aloca o bloco de bytes que guardará os caracteres da palavra atual
        palavras[i] = calloc(MAX, sizeof(char));
        fgets(palavras[i], MAX, stdin);

        // Substitui o primeiro caractere de nova linha (\n ou \r) pelo terminador '\0'
        palavras[i][strcspn(palavras[i], "\r\n")] = '\0';
    }

    // Loop que percorre o array de palavras da última para a primeira (ordem reversa)
    for (int j = n - 1; j >= 0; j--) {
        // Obtém o tamanho real da string (apenas caracteres visíveis após a limpeza)
        int tam = strlen(palavras[j]);

        // Imprime a palavra na ordem normal em que foi lida
        printf("%s\n", palavras[j]);

        // Percorre a string do último caractere até o primeiro, invertendo as letras
        for(int k = tam - 1; k >= 0; k--) {
            printf("%c", palavras[j][k]);
        }
        printf("\n");
    }

    // Libera a memória de cada palavra e depois o array de ponteiros
    for (int i = 0; i < n; i++) {
        free(palavras[i]);
    }
    free(palavras);

    return 0;
}
