#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    char txt[MAX];
    int n;
    double *valores;

    fgets(txt, sizeof(txt), stdin);
    n = atoi(txt);

    if (n <= 0) {
        return 1;
    }

    valores = (double*) calloc(n, sizeof(double));

    if (valores == NULL) {
        printf("Memoria insuficiente");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fgets(txt, sizeof(txt), stdin);
        valores[i] = atof(txt);
    }

    for (int i = n - 1; i >= 0; i--) {
        printf("%.2lf\n", valores[i]);
    }

    free(valores);

    return 0;
}
