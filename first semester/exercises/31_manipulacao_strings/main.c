#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AVISO: ESTE CÓDIGO SÓ FUNCIONARÁ EM MÁQUINAS LINUX DEVIDO ÀS DIFERENÇAS DOS SOs!!!

char txt[85];
char teste[] = "TESTE";
int tamanho;

int main()
{
    fflush(stdin);
    fgets(txt, 80, stdin);
    // Declara dois valores integers: countnorm para contar valores visíveis, enqaunto countesp para contar até mesmo os invisíveis (\r, \n, \0)
    int countnorm = 0;
    int countesp = 0;
    // For para contar a quantidade
    for (int i = 0; i < 85; i++){
        if (txt[i] >= 32){
            countnorm++;
        }
        countesp++;
        if (txt[i] == '\0'){
            break;
        }
    }
    printf("%d\n%d\n", countnorm, countesp);
    // Substituição dos valores escondidos por \0 para comparar com a string teste, que se fosse impressa, apareceria "TESTE\0"
    txt[strcspn(txt, "\r")] = '\0';
    txt[strcspn(txt, "\n")] = '\0';
    // Se o valor for igual a string teste, retornará OK
    if (strcmp(txt, teste) == 0) {
        printf("OK\n");
    } else {
        printf("NOT\n");
    }
    // Retorna os valores iniciais dos caracteres escondidos
    txt[strcspn(txt, "\r")] = '\r';
    txt[strcspn(txt, "\n")] = '\n';
    // Imprime contendo os valores iniciais
    for (int i = 0; i < countesp; i++){
        if (txt[i] >= 32){
            printf("%c (%d)\n", txt[i], txt[i]);
        }
        else{
            printf("? (%d)\n", txt[i]);
        }
    }
}
