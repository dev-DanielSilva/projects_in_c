#include <stdio.h>
#include <stdlib.h>

#include "LDED.h"

int main()
{
    // Elem  *el;
    Lista *li1, *lf1;
    Lista *li2, *lf2;


    cria_fila(&li1,&lf1);
    cria_fila(&li2,&lf2);

    int i;
    for(i=0; i < 5; i++)
    {
        insere_fila(li1,lf1,i);
        insere_fila(li2,lf2,i+60);
    }


    exibe_fila(lf1);
    exibe_fila(lf2);

    //remove_fila
    for(i=0; i < 5; i++)
    {
        remove_fila(li1,lf1);
        exibe_fila(lf1);
        printf("\n");
    }

    //libera_fila(li,lf);
    return 0;
}


