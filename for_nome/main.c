#include <stdio.h>
#include <stdlib.h>

char nome[];

int main()
{
    printf("Digite o nome: "); scanf("%s", nome);
    for (int i = 0; nome[i] != '\0'; i++){
        printf("%c\n", nome[i]);
    }
}
