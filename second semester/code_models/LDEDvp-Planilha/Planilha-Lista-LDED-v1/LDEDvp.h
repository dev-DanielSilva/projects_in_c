//Arquivo LDEDvp.h

#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

typedef struct {
    int  lin,col;
    int  tipo;       // 0=int; 1=float; 2=string; 3=formula
    int  lc;
    char cel[30];
} Tipo_Dado;

//Definição do tipo lista
struct elemento{
    struct elemento *ant;
    Tipo_Dado dado;
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int consulta_lista_pos(Lista* li, int pos, Tipo_Dado *dt);
int insere_lista_final(Lista* li, Tipo_Dado dt);
int insere_lista_inicio(Lista* li, Tipo_Dado dt);
int insere_lista_ordenada(Lista* li, Tipo_Dado dt);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
void imprime_lista(Lista* li);


