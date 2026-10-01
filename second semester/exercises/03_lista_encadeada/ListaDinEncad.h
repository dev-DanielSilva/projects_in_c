//Arquivo ListaDinEncad.h

struct s_dado{
    double valor;
};

typedef struct s_dado tipo_dado;

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, struct s_dado al);
int insere_lista_inicio(Lista* li, struct s_dado al);
int insere_lista_ordenada(Lista* li, struct s_dado al);
int remove_lista(Lista* li, tipo_dado dt);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
void imprime_lista(Lista* li);
