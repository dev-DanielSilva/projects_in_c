#include <stdio.h>
#include <stdlib.h>

#include "LDED.h"

FILE *ArqIn;

int main()
{
    Tipo_Dado dado;
    Tipo_Dado dado1,dado2;
    int RetPil1, RetPil2, RetPil3;
    int Tem_ValorP1eP2;
    // Elem  *el;
    Lista *li1 = cria_lista();
    Lista *li2 = cria_lista();
    Lista *li3 = cria_lista();
    Lista *li4 = cria_lista();

    // Lista 1
    printf("# Tamanho: %d\n",tamanho_lista(li1));
    ArqIn=fopen("tab1.txt","rt");
    if (ArqIn == NULL) { printf ("Help!\n"); exit(0); }

    while (!feof(ArqIn))
    {
        fscanf(ArqIn,"%d %f",&dado.seq,&dado.valor);
        insere_lista_ordenada(li1,dado);
        printf("Inserindo... %5d - %.5f\n",dado.seq,dado.valor);
    }
    fclose(ArqIn);
    printf("\nExibe Pilha: P1\n");
    imprime_lista(li1);
    printf("\n# Tamanho: %d\n",tamanho_lista(li1));

    system("pause");

    // Lista 2
    printf("\n# Tamanho: %d\n",tamanho_lista(li2));
    ArqIn=fopen("tab2.txt","rt");
    if (ArqIn == NULL) { printf ("Help!\n"); exit(0); }

    while (!feof(ArqIn))
    {
        fscanf(ArqIn,"%d %f",&dado.seq,&dado.valor);
        insere_lista_ordenada(li2,dado);
        printf("Inserindo... %5d - %.5f\n",dado.seq,dado.valor);
    }
    fclose(ArqIn);
    printf("\nExibe Pilha: P2\n");
    imprime_lista(li2);
    printf("\n# Tamanho: %d\n",tamanho_lista(li2));

    system("pause");

    // Merge Lista1 e Lista2 (ordenadas) em uma Lista3 (ordenada)

    RetPil1=desempilha_lista(li1,&dado1);
    RetPil2=desempilha_lista(li2,&dado2);

    if (RetPil1 && RetPil2)
       Tem_ValorP1eP2=OK;
    else
       Tem_ValorP1eP2=ERRO;

    while (Tem_ValorP1eP2)
    {
      if (dado1.valor < dado2.valor)
      {
          empilha_lista(li3,dado1);
          RetPil1=desempilha_lista(li1,&dado1);
      }
      else
      {
          empilha_lista(li3,dado2);
          RetPil2=desempilha_lista(li2,&dado2);
      }
      if (!RetPil1) Tem_ValorP1eP2=FALSO;
      if (!RetPil2) Tem_ValorP1eP2=FALSO;
    }

    if (!RetPil1) {
        while (RetPil2) {
                empilha_lista(li3,dado2);
                RetPil2=desempilha_lista(li2,&dado2);
        }
    }

    if (!RetPil2) {
        while (RetPil1) {
                empilha_lista(li3,dado1);
                RetPil1=desempilha_lista(li1,&dado1);
        }
    }

    printf("\nExibe Pilha: P3 (Merged)\n");
    imprime_lista(li3);
    printf("\n# Tamanho: %d\n",tamanho_lista(li3));

    system("pause");

    printf("\nInverte Pilha: P4\n");
    RetPil3=1;
    while (RetPil3)
    {
        RetPil3=desempilha_lista(li3,&dado1);
        if (RetPil3)
            empilha_lista(li4,dado1);
    }
    imprime_lista(li4);

    // FIM!
    libera_lista(li1);
    libera_lista(li2);

    return 0;

}

