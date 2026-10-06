#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LDED.h"

// ============================================================================
// --- GERENCIAMENTO DA LISTA ---
// ============================================================================

Lista* cria_lista()
{
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL) {
        *li = (Editor*) malloc(sizeof(Editor));
        if (*li != NULL) {
            (*li)->inicio = NULL;
            (*li)->fim = NULL;
            (*li)->cursor = NULL;
            (*li)->qtd = 0;
        } else {
            free(li);
            return NULL;
        }
    }
    return li;
}

void libera_lista(Lista* li)
{
    if (li != NULL && *li != NULL) {
        Elem* no = (*li)->inicio;
        while (no != NULL) {
            Elem* aux = no;
            no = no->prox;
            free(aux);
        }
        free(*li);
        *li = NULL;
        free(li);
    }
}

int tamanho_lista(Lista* li)
{
    if (li == NULL || *li == NULL)
        return 0;
    return (*li)->qtd;
}

int lista_cheia(Lista* li)
{
    return ERRO;
}

int lista_vazia(Lista* li)
{
    if (li == NULL || *li == NULL || (*li)->qtd == 0)
        return OK;
    return ERRO;
}

// ============================================================================
// --- INSERÇÃO (Comandos I, F, A, D) ---
// ============================================================================

int insere_lista_inicio(Lista* li, Tipo_Dado dt)
{
    if (li == NULL || *li == NULL)
        return ERRO;

    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;

    no->dado = dt;
    no->prox = (*li)->inicio;
    no->ant = NULL;

    if ((*li)->inicio != NULL) {
        (*li)->inicio->ant = no;
        (*li)->inicio = no;
    } else {
        (*li)->inicio = no;
        (*li)->fim = no;
    }

    (*li)->cursor = no;
    (*li)->qtd++;

    return OK;
}

int insere_lista_final(Lista* li, Tipo_Dado dt)
{
    if (li == NULL || *li == NULL)
        return ERRO;

    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;

    no->dado = dt;
    no->prox = NULL;

    if ((*li)->inicio == NULL) {
        no->ant = NULL;
        (*li)->inicio = no;
        (*li)->fim = no;
    } else {
        (*li)->fim->prox = no;
        no->ant = (*li)->fim;
        (*li)->fim = no;
    }

    (*li)->cursor = no;
    (*li)->qtd++;

    return OK;
}

int insere_lista_antes(Lista* li, Tipo_Dado dt)
{
    if (li == NULL || *li == NULL || (*li)->cursor == NULL)
        return ERRO;

    if ((*li)->cursor == (*li)->inicio) {
        return insere_lista_inicio(li, dt);
    }

    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;

    no->dado = dt;
    no->prox = (*li)->cursor;
    no->ant = (*li)->cursor->ant;

    (*li)->cursor->ant->prox = no;
    (*li)->cursor->ant = no;

    (*li)->cursor = no;
    (*li)->qtd++;

    return OK;
}

int insere_lista_depois(Lista* li, Tipo_Dado dt)
{
    if (li == NULL || *li == NULL || (*li)->cursor == NULL)
        return ERRO;

    if ((*li)->cursor == (*li)->fim) {
        return insere_lista_final(li, dt);
    }

    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;

    no->dado = dt;
    no->ant = (*li)->cursor;
    no->prox = (*li)->cursor->prox;

    (*li)->cursor->prox->ant = no;
    (*li)->cursor->prox = no;

    (*li)->cursor = no;
    (*li)->qtd++;

    return OK;
}

// ============================================================================
// --- REMOÇÃO (Comandos R e internas) ---
// ============================================================================

int remove_lista_inicio(Lista* li)
{
    if (li == NULL || *li == NULL || (*li)->inicio == NULL)
        return ERRO;

    Elem *no = (*li)->inicio;
    (*li)->inicio = no->prox;

    if (no->prox != NULL) {
        no->prox->ant = NULL;
    } else {
        (*li)->fim = NULL;
    }

    if ((*li)->cursor == no) {
        (*li)->cursor = (*li)->inicio;
    }

    (*li)->qtd--;
    free(no);

    return OK;
}

int remove_lista_final(Lista* li)
{
    if (li == NULL || *li == NULL || (*li)->fim == NULL)
        return ERRO;

    Elem *no = (*li)->fim;
    (*li)->fim = no->ant;

    if ((*li)->fim != NULL) {
        (*li)->fim->prox = NULL;
    } else {
        (*li)->inicio = NULL;
    }

    if ((*li)->cursor == no) {
        (*li)->cursor = (*li)->fim;
    }

    (*li)->qtd--;
    free(no);

    return OK;
}

int remove_lista_cursor(Lista* li)
{
    if (li == NULL || *li == NULL || (*li)->cursor == NULL)
        return ERRO;

    if ((*li)->cursor == (*li)->inicio)
        return remove_lista_inicio(li);

    if ((*li)->cursor == (*li)->fim)
        return remove_lista_final(li);

    Elem *no = (*li)->cursor;

    no->ant->prox = no->prox;
    no->prox->ant = no->ant;

    // Conforme especificação: após remover, cursor vai para o elemento anterior[cite: 2]
    (*li)->cursor = no->ant;
    (*li)->qtd--;

    free(no);
    return OK;
}

int remove_lista_elemento(Lista *li, Tipo_Dado dt)
{
    if (li == NULL || *li == NULL || (*li)->inicio == NULL)
        return ERRO;

    Elem *aux = (*li)->inicio;

    while (aux != NULL && strcmp(aux->dado.palavra, dt.palavra) != 0) {
        aux = aux->prox;
    }

    if (aux == NULL)
        return ERRO;

    if (aux == (*li)->inicio)
        return remove_lista_inicio(li);

    if (aux == (*li)->fim)
        return remove_lista_final(li);

    aux->prox->ant = aux->ant;
    aux->ant->prox = aux->prox;

    if ((*li)->cursor == aux) {
        (*li)->cursor = aux->prox;
    }

    (*li)->qtd--;
    free(aux);

    return OK;
}

int remove_lista(Lista* li, Tipo_Dado dt)
{
    return remove_lista_elemento(li, dt);
}

// ============================================================================
// --- NAVEGAÇÃO DO CURSOR (Comando G) ---
// ============================================================================

int avanca_cursor(Lista *li)
{
    if (li == NULL || *li == NULL || (*li)->cursor == NULL)
        return ERRO;

    if ((*li)->cursor->prox != NULL) {
        (*li)->cursor = (*li)->cursor->prox;
        return OK;
    }

    return ERRO;
}

int recua_cursor(Lista *li)
{
    if (li == NULL || *li == NULL || (*li)->cursor == NULL)
        return ERRO;

    if ((*li)->cursor->ant != NULL) {
        (*li)->cursor = (*li)->cursor->ant;
        return OK;
    }

    return ERRO;
}

int inicio_cursor(Lista *li)
{
    if (li == NULL || *li == NULL || (*li)->inicio == NULL)
        return ERRO;

    (*li)->cursor = (*li)->inicio;

    return OK;
}

int final_cursor(Lista *li)
{
    if (li == NULL || *li == NULL || (*li)->fim == NULL)
        return ERRO;

    (*li)->cursor = (*li)->fim;

    return OK;
}

// ============================================================================
// --- CONSULTA, BUSCA E EDICAO (Comandos P, T) ---
// ============================================================================

int consulta_lista_cursor(Lista *li, Tipo_Dado *dt)
{
    if (li == NULL || *li == NULL || (*li)->cursor == NULL || dt == NULL)
        return ERRO;

    *dt = (*li)->cursor->dado;

    return OK;
}

int consulta_lista_dado(Lista* li, Tipo_Dado dt)
{
    if (li == NULL || *li == NULL || (*li)->cursor == NULL)
        return ERRO;

    Elem *no = (*li)->cursor;
    while (no != NULL && strcmp(no->dado.palavra, dt.palavra) != 0) {
        no = no->prox;
    }

    if (no == NULL)
        return ERRO;

    (*li)->cursor = no;
    return OK;
}

int troca_palavra_cursor(Lista *li, char *nova_palavra)
{
    if (li == NULL || *li == NULL || (*li)->cursor == NULL || nova_palavra == NULL)
        return ERRO;

    strcpy((*li)->cursor->dado.palavra, nova_palavra);
    return OK;
}

// ============================================================================
// --- EXIBIÇÃO E ESTATÍSTICA (Comandos L e S) ---
// ============================================================================

int imprime_lista(Lista* li, const char *opcao)
{
    if (li == NULL || *li == NULL || (*li)->inicio == NULL || opcao == NULL)
        return ERRO;

    // CASO 1: IMPRIMIR TEXTO COMPLETO[cite: 2]
    if (strcmp(opcao, "texto") == 0) {
        Elem *aux = (*li)->inicio;
        while (aux != NULL) {
            printf("%s", aux->dado.palavra);
            if (aux->prox != NULL) {
                printf(" ");
            }
            aux = aux->prox;
        }
        printf("\n");
        return OK;
    }

    if ((*li)->cursor == NULL)
        return ERRO;

    // CASO 2: IMPRIMIR APENAS A PALAVRA SOB O CURSOR[cite: 2]
    if (strcmp(opcao, "palavra") == 0) {
        printf("%s\n", (*li)->cursor->dado.palavra);
        return OK;
    }

    // CASO 3: IMPRIMIR JANELA DE ATÉ 11 PALAVRAS AO REDOR DO CURSOR[cite: 2]
    // CASO 3: IMPRIMIR JANELA DE ATÉ 11 PALAVRAS AO REDOR DO CURSOR
    if (strcmp(opcao, "cursor") == 0) {
        Elem *inicio_janela = (*li)->cursor;

        // 1. Recua até no máximo 5 posições antes do cursor
        for (int i = 0; i < 5 && inicio_janela->ant != NULL; i++) {
            inicio_janela = inicio_janela->ant;
        }

        // 2. Determina até qual nó podemos ir (no máximo 5 posições após o cursor)
        Elem *fim_janela = (*li)->cursor;
        for (int i = 0; i < 5 && fim_janela->prox != NULL; i++) {
            fim_janela = fim_janela->prox;
        }

        // 3. Imprime do inicio_janela até o fim_janela
        Elem *aux = inicio_janela;
        while (aux != NULL) {
            printf("%s", aux->dado.palavra);

            if (aux == fim_janela) {
                break; // Parou no limite da janela à direita
            }

            if (aux->prox != NULL) {
                printf(" ");
            }
            aux = aux->prox;
        }

        printf("\n");
        return OK;
    }

    return ERRO;
}

void exibe_estatistica(Lista *li)
{
    if (li == NULL || *li == NULL) {
        printf("0\n");
        return;
    }
    printf("%d\n", (*li)->qtd); //[cite: 3]
}
