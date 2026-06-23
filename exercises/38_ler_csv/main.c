#include <stdio.h>
#include <stdlib.h>

FILE *Arqin;
double tabDados[10][10];

int main() {
    int nlin = 0;
    double dado, lixo;

    Arqin = fopen("dados.csv", "rt");
    if (Arqin == NULL) {
        printf("Erro na abertura \n");
        exit(-1);
    }

    while (nlin < 10) {
        for (int i = 0; i < 10; i++) {
            fscanf(Arqin, "%lf,", &dado);
            tabDados[nlin][i] = dado;
        }
        fscanf(Arqin, "%lf,", &lixo);  // descarta o 99.99 do fim da linha
        nlin++;
    }

    fclose(Arqin);

    for (nlin = 0; nlin < 10; nlin++) {
        for (int i = 0; i < 10; i++) {
            printf("%.2lf ", tabDados[nlin][i]);
        }
        printf("\n");
    }

    return 0;
}
