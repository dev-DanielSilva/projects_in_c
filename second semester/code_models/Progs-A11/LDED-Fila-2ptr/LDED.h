//Arquivo LDED.h - Lista Dinamica Encadeada Dupla

#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

typedef int  Tipo_Dado;

//Definição do tipo lista
struct elemento{
    struct elemento *ant;
    Tipo_Dado dado;
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento* Lista;

void cria_fila(Lista **li, Lista **lf);
void libera_fila(Lista* li, Lista* lf);
// int insere_lista_inicio(Lista* li, Lista* lf, Tipo_Dado dt);
int insere_fila(Lista* li, Lista* lf, Tipo_Dado dt);
// int remove_lista_final(Lista* li, Lista* lf);
int remove_fila (Lista* li, Lista* lf);
int tamanho_fila(Lista* li);
void exibe_fila(Lista* lf);

/* ===
int consulta_lista_pos(Lista* li, int pos, Tipo_Dado *dt);
int consulta_lista_dado(Lista* li, Tipo_Dado dt, Elem **el);
int insere_lista_final(Lista* li, Tipo_Dado dt);
int insere_lista_ordenada(Lista* li, Tipo_Dado dt);
int remove_lista(Lista* li, Tipo_Dado dt);
int remove_lista_inicio(Lista* li);
int lista_vazia(Lista* li);
=== */
