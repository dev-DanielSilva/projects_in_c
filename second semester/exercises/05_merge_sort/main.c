#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"

void carregar_arquivo(const char *nome_arquivo, Pilha *pi) {
    FILE *arq = fopen(nome_arquivo, "r");
    if (arq == NULL) {
        printf("ERRO AO ABRIR ARQUIVO: %s\n", nome_arquivo);
        exit(0);
    }

    char linha[100];
    Pilha *pi_aux = cria_Pilha();

    while (fgets(linha, sizeof(linha), arq) != NULL) {
        // Interrompe imediatamente ao encontrar o caracter '#'
        if (linha[0] == '#') {
            break;
        }

        // Se a linha comeca com um digito, converte o NUMERO INTEIRO COMPLETO (ex: "10" -> 10)
        if (linha[0] >= '0' && linha[0] <= '9') {
            int numero = atoi(linha);
            insere_Pilha(pi_aux, numero);
        }
    }

    fclose(arq);

    // Inverte para que o menor numero (o primeiro do ficheiro) fique no TOPO da pilha principal
    int val;
    while (!Pilha_vazia(pi_aux)) {
        consulta_topo_Pilha(pi_aux, &val);
        insere_Pilha(pi, val);
        remove_Pilha(pi_aux);
    }

    libera_Pilha(pi_aux);
}

void organiza_Pilha(Pilha *p1, Pilha *p2, Pilha *p_res) {
    int v1, v2;

    while (!Pilha_vazia(p1) && !Pilha_vazia(p2)) {
        consulta_topo_Pilha(p1, &v1);
        consulta_topo_Pilha(p2, &v2);

        if (v1 <= v2) {
            insere_Pilha(p_res, v1);
            remove_Pilha(p1);
        } else {
            insere_Pilha(p_res, v2);
            remove_Pilha(p2);
        }
    }

    while (!Pilha_vazia(p1)) {
        consulta_topo_Pilha(p1, &v1);
        insere_Pilha(p_res, v1);
        remove_Pilha(p1);
    }

    while (!Pilha_vazia(p2)) {
        consulta_topo_Pilha(p2, &v2);
        insere_Pilha(p_res, v2);
        remove_Pilha(p2);
    }
}

int main() {
    Pilha *p1 = cria_Pilha();
    Pilha *p2 = cria_Pilha();
    Pilha *p_res = cria_Pilha();
    Pilha *p_final = cria_Pilha();

    carregar_arquivo("nros1.txt", p1);
    carregar_arquivo("nros2.txt", p2);

    organiza_Pilha(p1, p2, p_res);

    // Passa de p_res para p_final para que os menores numeros fiquem no topo
    int val;
    while (!Pilha_vazia(p_res)) {
        consulta_topo_Pilha(p_res, &val);
        insere_Pilha(p_final, val);
        remove_Pilha(p_res);
    }

    imprime_Pilha(p_final);

    libera_Pilha(p1);
    libera_Pilha(p2);
    libera_Pilha(p_res);
    libera_Pilha(p_final);

    return 0;
}
