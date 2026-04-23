#include <stdio.h>
#include <stdlib.h>

int main()
{
    int peso1, peso2, peso3;
    float nota1, nota2, nota3;
    float media;

    scanf("%d%d%d", &peso1, &peso2, &peso3);
    scanf("%f%f%f", &nota1, &nota2, &nota3);

    media = (nota1 * peso1 + nota2 * peso2 + nota3 * peso3) / 100.00;
    printf("%.2f\n", media);

    return 0;
}
