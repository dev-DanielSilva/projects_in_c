#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

// Mudar para 0 para desativar saídas de debug e passar no corretor automático
#define DEBUG_RC 0

int main()
{
    int i, nmax, nlidos;
    double ult;
    tipo_dado dado;
    Lista *li_inicial, *li_final, *li_ordenada;

    scanf("%d", &nmax);    // Tamanho maximo da lista
    scanf("%d", &nlidos);  // Quantidade de dados a serem lidos

    if (DEBUG_RC) printf("Criando lista...\n");
    li_inicial = cria_lista(nmax);
    li_final = cria_lista(nmax);
    li_ordenada = cria_lista(nmax);
//
    for (i = 0; i < nlidos; i++)
    {
        scanf("%lf", &(dado.valor));

        if (DEBUG_RC) printf("Inserindo... %.2lf\n", dado.valor);
        if (!insere_lista_ordenada(li_ordenada, dado)) printf("ERRO\n");
        if (!insere_lista_inicio(li_inicial, dado)) printf("ERRO\n");
        if (!insere_lista_final(li_final, dado)) printf("ERRO\n");
    }
    ult = dado.valor; // Armazena o ultimo valor lido

    if (DEBUG_RC) printf("\n");

    // PRIMEIRA IMPRESSÃO
    if (DEBUG_RC) printf("Lista Inicio: \n");
    if (!DEBUG_RC) printf("inicio\n");
    imprime_lista(li_inicial);
    if (DEBUG_RC) printf("FIM LISTA\n\n");

    if (DEBUG_RC) printf("Lista final: \n");
    if (!DEBUG_RC) printf("final\n");
    imprime_lista(li_final);
    if (DEBUG_RC) printf("FIM LISTA\n\n");

    if (DEBUG_RC) printf("Lista Ordenada: \n");
    if (!DEBUG_RC) printf("ordenada\n");
    imprime_lista(li_ordenada);
    if (DEBUG_RC) printf("FIM LISTA\n\n");

    // REMOÇÃO DO ÚLTIMO ELEMENTO LIDO
    dado.valor = ult;
    if (DEBUG_RC) printf("\nValor Removido: %.2lf\n\n", dado.valor);

    if (!remove_lista(li_inicial, dado))  printf("ERRO\n");
    if (!remove_lista(li_final, dado))    printf("ERRO\n");
    if (!remove_lista(li_ordenada, dado)) printf("ERRO\n");

    if (DEBUG_RC) printf("\n");

    // SEGUNDA IMPRESSÃO
    if (DEBUG_RC) printf("Lista Inicio: \n");
    if (!DEBUG_RC) printf("inicio\n");
    imprime_lista(li_inicial);
    if (DEBUG_RC) printf("FIM LISTA\n\n");

    if (DEBUG_RC) printf("Lista Final \n");
    if (!DEBUG_RC) printf("final\n");
    imprime_lista(li_final);
    if (DEBUG_RC) printf("FIM LISTA\n\n");

    if (DEBUG_RC) printf("Lista Ordenada: \n");
    if (!DEBUG_RC) printf("ordenada\n");
    imprime_lista(li_ordenada);
    if (DEBUG_RC) printf("FIM LISTA\n\n");

    // LIBERAÇÃO DE MEMÓRIA
    libera_lista(li_inicial);
    libera_lista(li_final);
    libera_lista(li_ordenada);

    return 0;
}
