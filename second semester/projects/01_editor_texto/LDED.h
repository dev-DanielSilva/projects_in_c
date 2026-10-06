// Arquivo LDED.h - Lista Dinamica Encadeada Dupla
#ifndef LDED_H
#define LDED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK   1
#define ERRO 0

// Define o tipo de dado armazenado (palavra de até 12 caracteres + '\0')
typedef struct {
    char palavra[13];
} Tipo_Dado;

// Estrutura do nó da lista
typedef struct elemento {
    struct elemento *ant;
    Tipo_Dado dado;
    struct elemento *prox;
} Elem;

// Descritor da lista
typedef struct {
    Elem *inicio;
    Elem *fim;
    Elem *cursor; // Cursor sobre a palavra atual
    int qtd;
} Editor;

typedef Editor* Lista;

// --- GERENCIAMENTO DA LISTA ---
Lista* cria_lista();
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);

// --- INSERÇÃO (Comandos I, F, A, D) ---
int insere_lista_inicio(Lista* li, Tipo_Dado dt);
int insere_lista_final(Lista* li, Tipo_Dado dt);
int insere_lista_antes(Lista* li, Tipo_Dado dt);
int insere_lista_depois(Lista* li, Tipo_Dado dt);

// --- REMOÇÃO (Comandos R e internas) ---
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int remove_lista_cursor(Lista* li);
int remove_lista_elemento(Lista* li, Tipo_Dado dt);
int remove_lista(Lista* li, Tipo_Dado dt); // Caso mantida para compatibilidade

// --- NAVEGAÇÃO DO CURSOR (Comando G) ---
int avanca_cursor(Lista *li);
int recua_cursor(Lista *li);
int inicio_cursor(Lista *li);
int final_cursor(Lista *li);

// --- CONSULTA, BUSCA E EDICAO (Comandos P, T) ---
int consulta_lista_cursor(Lista *li, Tipo_Dado *dt);
int consulta_lista_dado(Lista* li, Tipo_Dado dt);
int troca_palavra_cursor(Lista *li, char *nova_palavra);

// --- EXIBIÇÃO E ESTATÍSTICA (Comandos L e S) ---
int imprime_lista(Lista* li, const char *opcao);
void exibe_estatistica(Lista *li);

#endif // LDED_H
