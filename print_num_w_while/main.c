#include <stdio.h>
#include <stdlib.h>

char txt[30];
int vetor[50], num, qtd;

int main()
{
    fflush(stdin);
    fgets(txt, sizeof(txt), stdin);
    qtd = atoi(txt);
    if (qtd < 0 || qtd > 50) { printf("ERRO"); return(1); }

    else {
        int cont = 0;
        while (cont < qtd) {
            fflush(stdin);
            fgets(txt, sizeof(txt), stdin);
            num = atoi(txt);
            vetor[cont] = num;
            cont++;
        }
        cont = qtd;
        while(cont >= 1){
            printf("%d\n", vetor[cont - 1]);
            cont--;
        }
    }
}
