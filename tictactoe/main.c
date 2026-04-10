#include <stdio.h>

int main() {
    int tabuleiro[9] = {0};
    int posicao, jogador = 1, jogadas = 0;

    for (;;) {
        scanf("%d", &posicao);

        if (posicao == -1) {
            printf("Jogada Valida -1\nFIM DE JOGO\n");
            break;
        }

        if (posicao >= 1 && posicao <= 9 && tabuleiro[posicao-1] == 0) {
            tabuleiro[posicao-1] = jogador;
            jogadas++;

            printf("Jogada Valida %d\n", posicao);

            // Verifica vitória
            if ((tabuleiro[0] && tabuleiro[0]==tabuleiro[1] && tabuleiro[0]==tabuleiro[2]) ||
                (tabuleiro[3] && tabuleiro[3]==tabuleiro[4] && tabuleiro[3]==tabuleiro[5]) ||
                (tabuleiro[6] && tabuleiro[6]==tabuleiro[7] && tabuleiro[6]==tabuleiro[8]) ||
                (tabuleiro[0] && tabuleiro[0]==tabuleiro[4] && tabuleiro[0]==tabuleiro[8]) ||
                (tabuleiro[2] && tabuleiro[2]==tabuleiro[4] && tabuleiro[2]==tabuleiro[6]) ||
                (tabuleiro[0] && tabuleiro[0]==tabuleiro[3] && tabuleiro[0]==tabuleiro[6]) ||
                (tabuleiro[1] && tabuleiro[1]==tabuleiro[4] && tabuleiro[1]==tabuleiro[7]) ||
                (tabuleiro[2] && tabuleiro[2]==tabuleiro[5] && tabuleiro[2]==tabuleiro[8])) {
                printf("Jogador %d venceu!\n", jogador);
                printf("Tabuleiro:\n");
                for (int i = 0; i < 9; i++) {
                    if (i > 0 && i % 3 == 0) printf("\n");
                    if (i % 3 == 0)
                        printf("%d", tabuleiro[i]);
                    else
                        printf(" %d", tabuleiro[i]);
                }
                printf("\n");
                break;
            }

            if (jogadas == 9) {
                printf("Empate!\n");
                printf("Tabuleiro:\n");
                for (int i = 0; i < 9; i++) {
                    if (i > 0 && i % 3 == 0) printf("\n");
                    if (i % 3 == 0)
                        printf("%d", tabuleiro[i]);
                    else
                        printf(" %d", tabuleiro[i]);
                }
                printf("\n");
                break;
            }

            jogador = (jogador == 1) ? 2 : 1;
            if (jogador == 1) {
                printf("Jogador 1 joga agora!\n");
            } else {
                printf("Jogador 2 joga agora!\n");
            }

            printf("Tabuleiro:\n");
            for (int i = 0; i < 9; i++) {
                if (i > 0 && i % 3 == 0) printf("\n");
                if (i % 3 == 0)
                    printf("%d", tabuleiro[i]);
                else
                    printf(" %d", tabuleiro[i]);
            }
            printf("\n");
        } else {
            printf("Jogada Invalida %d\n", posicao);

            if (jogador == 1) {
                printf("Jogador 1 joga agora!\n");
            } else {
                printf("Jogador 2 joga agora!\n");
            }

            printf("Tabuleiro:\n");
            for (int i = 0; i < 9; i++) {
                if (i > 0 && i % 3 == 0) printf("\n");
                if (i % 3 == 0)
                    printf("%d", tabuleiro[i]);
                else
                    printf(" %d", tabuleiro[i]);
            }
            printf("\n");
        }
    }
}
