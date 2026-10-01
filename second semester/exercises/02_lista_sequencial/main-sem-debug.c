#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

int main()
{
    int i,nmax,nlidos;
    double ult;
    tipo_dado dado;
    Lista *liini, *lifim,*liord;

    scanf("%d",&nmax);      // Tamanho maximo da lista
    scanf("%d",&nlidos);    // Quantidade de dados a serem lidos

    liini = cria_lista(nmax);
    lifim = cria_lista(nmax);
    liord = cria_lista(nmax);

    for (i=0; i < nlidos; i++)
    {
        scanf("%lf",&(dado.valor));
        if (!insere_lista_ordenada(liord,dado)) printf("ERRO\n");
        if (!insere_lista_inicio(liini,dado)) printf("ERRO\n");
        if (!insere_lista_final(lifim,dado)) printf("ERRO\n");
    }
    ult=dado.valor;

    printf("inicio\n");
    imprime_lista(liini);

    printf("final\n");
    imprime_lista(lifim);

    printf("ordenada\n");
    imprime_lista(liord);

    dado.valor=ult;
     if (!remove_lista(liini,dado))
            printf("ERRO\n");
    if (!remove_lista(lifim,dado))
            printf("ERRO\n");
    if (!remove_lista(liord,dado))
            printf("ERRO\n");

    printf("inicio\n");
    imprime_lista(liini);

    printf("final\n");
    imprime_lista(lifim);

    printf("ordenada\n");
    imprime_lista(liord);

    libera_lista(liini);
    libera_lista(lifim);
    libera_lista(liord);

    return 0;
}

