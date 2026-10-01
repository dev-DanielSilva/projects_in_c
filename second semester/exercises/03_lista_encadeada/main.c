#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

int main(){

    Lista* li_inicio = cria_lista();
    Lista* li_final = cria_lista();
    Lista* li_ordenada = cria_lista();

    if (li_inicio == NULL || li_final == NULL || li_ordenada == NULL) {
        printf("ERRO");
        return 1;
    }

    char buffer[100];
    tipo_dado dado, ultimo_dado;
    int leu_algum = 0;

    while(fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (buffer[0] == '#'){
            break;
        }

        dado.valor = atof(buffer);
        ultimo_dado = dado; //Registra valor posterior
        leu_algum = 1;

        if (!insere_lista_inicio(li_inicio, dado) ||
            !insere_lista_final(li_final, dado) ||
            !insere_lista_ordenada(li_ordenada, dado)) {
            printf("ERRO\n");
        }
    }

    printf("inicio\n");
    imprime_lista(li_inicio);

    printf("final\n");
    imprime_lista(li_final);

    printf("ordenada\n");
    imprime_lista(li_ordenada);

    if (leu_algum) {
        remove_lista(li_inicio, ultimo_dado);
        remove_lista(li_final, ultimo_dado);
        remove_lista(li_ordenada, ultimo_dado);
    }

    printf("inicio\n");
    imprime_lista(li_inicio);

    printf("final\n");
    imprime_lista(li_final);

    printf("ordenada\n");
    imprime_lista(li_ordenada);

    libera_lista(li_inicio);
    libera_lista(li_final);
    libera_lista(li_ordenada);

    return 0;
}

