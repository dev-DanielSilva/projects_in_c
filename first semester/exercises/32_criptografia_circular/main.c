#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int crypt;
char txt[25];
char senha[7];

// ATENÇÃO: CÓDIGO SÓ FUNCIONARÁ EM SISTEMAS LINUX

int main()
{
    // Inicia o contador
    int contador = 0;
    // Ler valores da senha
    fgets(senha, sizeof(senha), stdin);
    // Ler valores da txt
    fgets(txt, 20, stdin);
    // Transforma "\r" em "\0"
    txt[strcspn(txt, "\r")] = '\0';
    // Começa o Loop para criptografia
    for (int i = 0; i < strlen(txt); i++){
        // Termina o loop se encontrar o caracter \0
        if (txt[i] == "\0"){
            break;
        }
        // Transforma o caracter senha[contador] em número
        int valor_senha = senha[contador] - '0';
        // Execução da criptografia
        txt[i] = txt[i] + valor_senha;
        contador++;
        // Reinicia o ciclo se contador = 4
        if (contador % 4 == 0){
            contador = 0;
        }
    }
    printf("%s", txt);
}
