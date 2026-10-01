#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"

// Função auxiliar para carregar o arquivo para a pilha
void carregar_arquivo(const char *nome_arquivo, Pilha *pi) {
    FILE *arq = fopen(nome_arquivo, "r");
    if (arq == NULL){
        printf("ERRO AO ABRIR ARQUIVO \n");
        exit(0);
    }
    char linha[100];

    while(fgets(linha, sizeof(linha),arq) != NULL) {
        if (linha[0] == '#') {
            break;
        }

        if (linha[0] >= '0' && linha[0] <= '9') {
            int digito = linha[0] - '0';
            insere_Pilha(pi, digito);
        }
    }

    fclose(arq);
}

int main() {
    Pilha *p1 = cria_Pilha();
    Pilha *p2 = cria_Pilha();
    Pilha *p_res = cria_Pilha();

    carregar_arquivo("arq-nro1.txt", p1);
    carregar_arquivo("arq-nro2.txt", p2);

    int vai_um = 0;

    while(!Pilha_vazia(p1) || !Pilha_vazia(p2) || vai_um > 0) {
        int d1 = 0;
        int d2 = 0;

        if (!Pilha_vazia(p1)) {
            consulta_topo_Pilha(p1, &d1);
            remove_Pilha(p1);
        }
        if (!Pilha_vazia(p2)) {
            consulta_topo_Pilha(p2, &d2);
            remove_Pilha(p2);
        }

        int soma = d1 + d2 + vai_um;
        int digito_resultado = soma % 10;
        vai_um = soma / 10;

        insere_Pilha(p_res, digito_resultado);
    }

    imprime_Pilha(p_res);

    libera_Pilha(p1);
    libera_Pilha(p2);
    libera_Pilha(p_res);

    return 0;

}
