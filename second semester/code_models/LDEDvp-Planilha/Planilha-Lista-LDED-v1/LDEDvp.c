//Arquivo LDEDvp.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LDEDvp.h" //inclui os Protótipos

int NumNodos=0;

Lista* cria_lista()
{
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li)
{
    if (li != NULL)
	{
        Elem* no;
        while ((*li) != NULL)
		{
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int consulta_lista_pos(Lista* li, int pos, Tipo_Dado *dt)
{
    if (li == NULL || pos <= 0)
        return ERRO;
    Elem *no = *li;
    int i = 1;
    while (no != NULL && i < pos)
	{
        no = no->prox;
        i++;
    }
    if (no == NULL)
        return ERRO;
    else
	{
        *dt = no->dado;
        return OK;
    }
}

int insere_lista_final(Lista* li, Tipo_Dado dt)
{
    Elem *no;

    if (li == NULL) return ERRO;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)  return ERRO;

    no->dado = dt;
    no->prox = NULL;

	if ((*li) == NULL)
	{   //lista vazia: insere início
        no->ant = NULL;
        *li = no;
    }else
	{
        Elem *aux;
        aux = *li;
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return OK;
}

int insere_lista_inicio(Lista* li, Tipo_Dado dt)
{
    if (li == NULL)
        return ERRO;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;

    no->dado = dt;
    no->prox = (*li);
    no->ant = NULL;

	if (*li != NULL) //lista não vazia: apontar para o anterior!
        (*li)->ant = no;
    *li = no;
    return OK;
}

int insere_lista_ordenada(Lista* li, Tipo_Dado dt)
{
    if (li == NULL)
        return ERRO;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;
    no->dado = dt;
    if ((*li) == NULL)
	{  //lista vazia: insere início
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return OK;
    }
    else{
        Elem *ante, *atual = *li;

        while (atual != NULL && atual->dado.lc <= dt.lc)
		{
            ante = atual;
            atual = atual->prox;
        }

        if (atual == *li)
		{   //insere início
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        } else
		{
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            if (atual != NULL)
                atual->ant = no;
        }
        return OK;
    }
}

int remove_lista_inicio(Lista* li)
{
    if (li == NULL)
        return ERRO;
    if ((*li) == NULL)//lista vazia
        return ERRO;

    Elem *no = *li;
    *li = no->prox;
    if (no->prox != NULL)
        no->prox->ant = NULL;

    free(no);
    return OK;
}

int remove_lista_final(Lista* li)
{
    if (li == NULL)
        return ERRO;
    if ((*li) == NULL) //lista vazia
        return ERRO;

    Elem *no = *li;
    while (no->prox != NULL)
        no = no->prox;

    if (no->ant == NULL) //remover o primeiro e único
        *li = no->prox;
    else
        no->ant->prox = NULL;

    free(no);
    return OK;
}

int tamanho_lista(Lista* li)
{
    if (li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while (no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li)
{
    return FALSO;
}

int lista_vazia(Lista* li)
{
    if (li == NULL)
        return OK;
    if (*li == NULL)
        return OK;
    return FALSO;
}

void imprime_lista(Lista* li)
{
    Elem* no = *li;

    printf("\n-------------- INICIO TEXTO -----------------\n");

    if (li == NULL)
        return;
    while (no != NULL)
    {
        printf("Dado(%d,%d): [%d] %s\n",no->dado.lin, no->dado.col, no->dado.tipo, no->dado.cel);
        no = no->prox;
    }
    printf("\n-------------- FIM TEXTO -----------------\n");
}
