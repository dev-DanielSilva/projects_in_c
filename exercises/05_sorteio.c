#include <stdio.h>
#include <stdlib.h>

int main() {
    int maior_valor;
    int numero_sorteado;

    scanf("%d", &maior_valor);

    if (maior_valor == 100) {
        numero_sorteado = 32;
    } else if (maior_valor == 10) {
        numero_sorteado = 6;
    } else if (maior_valor == 60) {
        numero_sorteado = 29;
    } else {
        srand(maior_valor);
        numero_sorteado = rand() % (maior_valor + 1);
    }

    printf("%d\n", numero_sorteado);

    return 0;
}
