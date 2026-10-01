#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

#define DEBUG_RC 0

int main()
{
    int i,nmax,nlidos;
    double ult;
    tipo_dado dado;
    Lista *liini, *lifim,*liord;

    scanf("%d",&nmax);      // Tamanho maximo da lista
    scanf("%d",&nlidos);    // Quantidade de dados a serem lidos


    if (DEBUG_RC) printf("Criando lista...\n");
    liini = cria_lista(nmax);
    lifim = cria_lista(nmax);
    liord = cria_lista(nmax);

    // srand(0);

    for (i=0; i < nlidos; i++)
    {
        scanf("%lf",&(dado.valor));
        //dado.valor = rand();

        if (DEBUG_RC) printf("Inserindo... %.2lf\n",dado.valor);
        if (!insere_lista_ordenada(liord,dado)) printf("ERRO\n");
        if (!insere_lista_inicio(liini,dado)) printf("ERRO\n");
        if (!insere_lista_final(lifim,dado)) printf("ERRO\n");
    }
    ult=dado.valor;

    if (DEBUG_RC) printf("\n");

    if (DEBUG_RC) printf("Lista Inicio: \n");
    if (!DEBUG_RC) printf("inicio\n");
    imprime_lista(liini);
    if (DEBUG_RC) printf("FIM LISTA\n");
    if (DEBUG_RC) printf("\n");


    if (DEBUG_RC) printf("Lista final: \n");
    if (!DEBUG_RC) printf("final\n");
    imprime_lista(lifim);
    if (DEBUG_RC) printf("FIM LISTA\n");
    if (DEBUG_RC) printf("\n");

    if (DEBUG_RC) printf("Lista Ordenada: \n");
    if (!DEBUG_RC) printf("ordenada\n");
    imprime_lista(liord);
    if (DEBUG_RC) printf("FIM LISTA\n");
    if (DEBUG_RC) printf("\n");

    // srand(0);
    dado.valor=ult;
    if (DEBUG_RC) printf("\nValor Removido: %.2lf\n\n",dado.valor);

    //dado.valor=rand();
    if (!remove_lista(liini,dado))
            printf("ERRO\n");
    if (!remove_lista(lifim,dado))
            printf("ERRO\n");
    if (!remove_lista(liord,dado))
            printf("ERRO\n");

    // imprime_lista(liord);

    if (DEBUG_RC) printf("\n");

    if (DEBUG_RC)  printf("Lista Inicio: \n");
    if (!DEBUG_RC) printf("inicio\n");
    imprime_lista(liini);
    if (DEBUG_RC) printf("FIM LISTA\n");
    if (DEBUG_RC) printf("\n");

    if (DEBUG_RC) printf("Lista \final: \n");
    if (!DEBUG_RC) printf("final\n");
    imprime_lista(lifim);
    if (DEBUG_RC) printf("FIM LISTA\n");
    if (DEBUG_RC) printf("\n");

    if (DEBUG_RC) printf("Lista Ordenada: \n");
    if (!DEBUG_RC) printf("ordenada\n");
    imprime_lista(liord);
    if (DEBUG_RC) printf("FIM LISTA\n");
    if (DEBUG_RC) printf("\n");

    libera_lista(liini);
    libera_lista(lifim);
    libera_lista(liord);

    return 0;
}

