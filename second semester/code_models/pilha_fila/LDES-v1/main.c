#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

int main()
{
    Elem *Ptr;
    Lista* li = cria_lista();

    printf("Tamanho: %d\n\n\n\n",tamanho_lista(li));

    int i;
    for(i=0; i <= 8; i+=2)
        insere_lista_ordenada(li,i);

    imprime_lista(li);
    printf("\n\n\n\n Tamanho: %d\n",tamanho_lista(li));

    for(i=0; i < 5; i++){
        remove_lista_final(li);
        imprime_lista(li);
        printf("\n Tamanho: %d\n\n\n",tamanho_lista(li));
    }

    // Cria uma lista com valores duplicados (3)
    insere_lista_inicio(li,5);
    insere_lista_inicio(li,3);
    insere_lista_inicio(li,8);
    insere_lista_inicio(li,1);
    insere_lista_inicio(li,3);
    insere_lista_inicio(li,7);
    insere_lista_inicio(li,9);
    insere_lista_inicio(li,4);
    insere_lista_inicio(li,6);
    insere_lista_inicio(li,3);
    insere_lista_inicio(li,2);

    imprime_lista(li);

    // Procura pelas multiplas ocorrencias de um valor (3)
    int achou=1;
    Ptr = *li;
    while (achou)
    {
       if (consulta_lista_dado(&Ptr, 3, &Ptr))
       {
           printf("Consulta Dado: 3 => Achou - %p \n",Ptr);
           Ptr = Ptr->prox;
       }
        else
        {
            printf("Fim lista\n");
            achou=0;
        }
    }

    if (consulta_lista_dado(li, 44, &Ptr))
        printf("Consulta Dado: 44 => Achou - %p \n",Ptr);
    else
        printf("Consulta Dado: 44 => Nao Achou\n");

    system("Pause");

    // Insere depois do dado (7)
    if (consulta_lista_dado(li, 7, &Ptr))
    {
       printf("Consulta Dado: 7 => Achou - %p \n",Ptr);
       insere_lista_depois(li,71,&Ptr);
       insere_lista_depois(li,72,&Ptr);
       insere_lista_depois(li,73,&Ptr);
       insere_lista_depois(li,74,&Ptr);
    }
    imprime_lista(li);

    system ("Pause");

    // Insere depois do dado (5) - Insere no final da lista
    if (consulta_lista_dado(li, 5, &Ptr))
    {
       printf("Consulta Dado: 5 => Achou - %p \n",Ptr);
       insere_lista_depois(li,51,&Ptr);
       insere_lista_depois(li,52,&Ptr);
       insere_lista_depois(li,53,&Ptr);
       insere_lista_depois(li,54,&Ptr);
    }
    imprime_lista(li);

    system ("Pause");

    // Insere antes do dado (7)
    if (consulta_lista_dado(li, 7, &Ptr))
    {
       printf("Consulta Dado: 7 => Achou - %p \n",Ptr);
       insere_lista_antes(li,69,&Ptr);
       insere_lista_antes(li,68,&Ptr);
       insere_lista_antes(li,67,&Ptr);
       insere_lista_antes(li,66,&Ptr);
    }
    imprime_lista(li);

    system ("Pause");

    // Insere antes do dado (2)  - Primeiro da Lista
    if (consulta_lista_dado(li, 2, &Ptr))
    {
       printf("Consulta Dado: 2 => Achou - %p \n",Ptr);
       insere_lista_antes(li,1,&Ptr);
    }
    imprime_lista(li);

    // Insere antes do dado (54)  - Ultimo da Lista
    if (consulta_lista_dado(li, 54, &Ptr))
    {
       printf("Consulta Dado: 54 => Achou - %p \n",Ptr);
       insere_lista_antes(li,1,&Ptr);
    }
    imprime_lista(li);

    system ("Pause");


    libera_lista(li);
    system("pause");
    return 0;
}

