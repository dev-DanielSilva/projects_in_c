#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LDEDvp.h"

int main()
{
    Lista *li;
    Tipo_Dado Dado;
    int plin=1,pcol=1;
    int repete;

    li = cria_lista();

    // Cria um primeiro nodo "Texto:"
    strcpy(Dado.cel,"Planilha:");
    Dado.tipo=-1;
    Dado.lin=0;
    Dado.col=0;
    insere_lista_inicio(li,Dado);

    printf("\n>> Planilha Simples <<\n");
    printf("Tamanho Inicial: %d\n",tamanho_lista(li));
    printf("\n");
    system("pause");
    repete=1;
    while (repete)
    {
       printf("Lin: ");
       scanf("%d",&plin);

       if (plin < 0) break;

       printf("Col: ");
       scanf("%d",&pcol);
       printf("Dado: ");
       Dado.lin=plin;
       Dado.col=pcol;
       Dado.lc=plin*1000+pcol;    // Max: 999 linhas e 999 colunas
       scanf("%s",Dado.cel);
       if (Dado.cel[0]>='0' && Dado.cel[0]<='9')
       {
          if (strchr(Dado.cel,'.') != NULL)
             Dado.tipo=1;   // Tipo pto. flutuante
          else
             Dado.tipo=0;
       }
       else
       if (Dado.cel[0]=='@') { Dado.tipo=3; }
       else Dado.tipo=2;    // tipo string

       insere_lista_ordenada(li,Dado);
    }

    printf("\n");
    printf(">> Fim da Edicao\n");
    printf("   Tamanho: %d\n",tamanho_lista(li));

    imprime_lista(li);
    libera_lista(li);
    return 0;
}

