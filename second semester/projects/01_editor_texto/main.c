#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LDED.h"

void carrega_arquivo(Lista *li) {
    FILE *f = fopen("texto.txt", "r");
    if (f == NULL)
        return; // Se o arquivo não existir, inicia com lista vazia

    Tipo_Dado dt;
    while (fscanf(f, "%12s", dt.palavra) == 1) {
        if (strcmp(dt.palavra, "FIM") == 0)
            break; // A palavra 'FIM' não entra na lista
        insere_lista_final(li, dt);
    }
    fclose(f);
    inicio_cursor(li); // Cursor começa no início
}

void salva_arquivo(Lista *li) {
    if (li == NULL || *li == NULL) return;
    FILE *f = fopen("texto-ed.txt", "w");

    if (f == NULL) return;

    Elem *aux = (*li)->inicio;
    while (aux != NULL) {
        fprintf(f, "%s", aux->dado.palavra);
        if (aux->prox != NULL) {
            fprintf(f, " ");
        }
        aux = aux->prox;
    }
    fclose(f);
}

int main()
{
    Lista *li = cria_lista();

    if (li == NULL) {
        return 1;
    }

    carrega_arquivo(li);

    char cmd[10];
    char arg[50];

    while (fscanf(stdin, "%s %s", cmd, arg) == 2) {
        // Encerramento (X)
        if (strcmp(cmd, "X") == 0) {
            break; // Sai do laço de leitura para salvar e encerrar
        }
        // INSERÇÃO (I, F, A, D)
        else if (strcmp(cmd, "I") == 0) {
            Tipo_Dado dt;
            strncpy(dt.palavra, arg, 12);
            dt.palavra[12] = '\0';
            insere_lista_inicio(li, dt);
        }
        else if (strcmp(cmd, "F") == 0) {
            Tipo_Dado dt;
            strncpy(dt.palavra, arg, 12);
            dt.palavra[12] = '\0';
            insere_lista_final(li, dt);
        }
        else if (strcmp(cmd, "A") == 0) {
            Tipo_Dado dt;
            strncpy(dt.palavra, arg, 12);
            dt.palavra[12] = '\0';
            insere_lista_antes(li, dt);
        }
        else if (strcmp(cmd, "D") == 0) {
            Tipo_Dado dt;
            strncpy(dt.palavra, arg, 12);
            dt.palavra[12] = '\0';
            insere_lista_depois(li, dt);
        }
        // BUSCA E SUBSTITUIÇÃO (P, T)
        else if (strcmp(cmd, "P") == 0) {
            Tipo_Dado dt;
            strncpy(dt.palavra, arg, 12);
            dt.palavra[12] = '\0';
            consulta_lista_dado(li, dt);
        }
        else if (strcmp(cmd, "T") == 0) {
            troca_palavra_cursor(li, arg);
        }
        // REMOÇÃO (R)
        else if (strcmp(cmd, "R") == 0) {
            if (strcmp(arg, "atual") == 0) {
                remove_lista_cursor(li);
            }
        }
        // Navegação do Cursor (G)
        else if (strcmp(cmd, "G") == 0) {
            if (strcmp(arg, "inicio") == 0) {
                inicio_cursor(li);
            }
            else if (strcmp(arg, "fim") == 0) {
                final_cursor(li);
            }
            else if (strcmp(arg, "prox") == 0) {
                avanca_cursor(li);
            }
            else if (strcmp(arg, "ant") == 0) {
                recua_cursor(li);
            }
        }
        // Listagem (L)
        else if (strcmp(cmd, "L") == 0) {
            imprime_lista(li, arg);
        }
        // Estatística (S)
        else if (strcmp(cmd, "S") == 0) {
            if (strcmp(arg, "texto") == 0) {
                exibe_estatistica(li);
            }
        }
    }

    // Salva o arquivo e libera a memória após sair do laço do editor
    salva_arquivo(li);
    libera_lista(li);

    return 0;
}
