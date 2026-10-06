#include <stdio.h>
#include <stdlib.h>

#include "LDED.h"

#define DEBUG 0

int main()
{
    // Elem  *el;
    //Lista *li, *lf;
    Lista *li=NULL;
    Lista *lf=NULL;
    int i;

    if (DEBUG)
        printf("Antes da Cria - li: %p -- lf: %p\n",li,lf);
    cria_fila(&li,&lf);
    if (DEBUG)
        printf("Apos da Cria  - li: %p -- lf: %p # *li: %p --  *lf: %p\n",li,lf,*li,*lf);


    printf(">> Criando FILA <<\n");

    for(i=0; i < 5; i++)
    {
        insere_fila(li,lf,i);
        exibe_fila(lf);         // Exibe do final para o inicio

        if (DEBUG)
            printf("Inseriu nodo (%d)- li: %p -- lf: %p # *li: %p --  *lf: %p\n",i,li,lf,*li,*lf);

    }
    if (DEBUG)
        printf("Apos insercoes- li: %p -- lf: %p # *li: %p --  *lf: %p\n",li,lf,*li,*lf);

    if (DEBUG)
        system("pause");

    exibe_fila(lf);

    //remove_fila
    for(i=0; i < 5; i++)
    {
        remove_fila(li,lf);
        exibe_fila(lf);
        printf("\n");
    }

    //libera_fila(li,lf);
    return 0;
}



