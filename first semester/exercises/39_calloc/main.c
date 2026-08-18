#include <stdio.h>
#include <stdlib.h> //Obrigatório para usar calloc

#define MAX 100

int main()
{
    char txt[MAX];
    int n, i;
    int *valores;

    fgets(txt, sizeof(txt), stdin);
    n = atoi(txt);

    if (n <= 0){
        return 1;
    }

    valores = (int*) calloc(n, sizeof(int));

    if (valores == NULL) {
        printf("Memori insuficiente");
        return 1;
    }

    for (i = 0; i < n; i++) {
        fgets(txt, sizeof(txt), stdin);
        valores[i] = atoi(txt);
    }

    for (i = n - 1; i >= 0; i--) {
        printf("%d\n", valores[i]);
    }

    free(valores);

    return 0;
}
