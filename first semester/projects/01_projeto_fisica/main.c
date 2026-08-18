#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int main() {
    float posicao = 0.0;
    float velocidade = 1.0;
    float aceleracao = 0.0;

    int limite_esquerdo = 0;
    int limite_direito = 60;
    char tecla;

    printf("Aperte qualquer tecla para comecar...");
    getch();

    while(1){
        if(kbhit()) {
            tecla = getch();

            if (tecla == 'w' || tecla == 'W') {
                aceleracao += 0.05;
            }
            else if (tecla == 's' || tecla == 'S') {
                aceleracao -= 0.05;
            }
            else if (tecla == ' ') {
                aceleracao = 0.0;
            }
        }
        system("cls");

        velocidade += velocidade * aceleracao;
        posicao = posicao + velocidade;

        if (posicao >= limite_direito) {
            posicao = limite_direito;
            velocidade = velocidade * -1;
        }
        else if (posicao <= limite_esquerdo) {
            posicao = limite_esquerdo;
            velocidade = velocidade * -1;
        }

        printf("Posicao %.2f | Velocidade %.2f| Aceleracao %.2f\n", posicao, velocidade, aceleracao);
        printf("Use W/S para acelerar/desacelerar o bloco\n");
        printf("------------------------------------------------------------\n");


        // 1. Desenha a parede esquerda
        printf("|");

        // 2. Desenha os espaços até chegar na posição do X
        // Começamos o 'i' em 1 porque a parede esquerda já ocupou a coluna 0
        for (int i = 1; i < (int)posicao; i++) {
            printf(" ");
        }

        // 3. Desenha o bloco (Só imprimimos o X se ele não estiver colado na parede direita)
        if ((int)posicao < limite_direito) {
            printf("X");
        }

        // 4. Desenha os espaços restantes da direita para alinhar a última barra
        int espacos_restantes = limite_direito - (int)posicao;
        for (int j = 1; j < espacos_restantes; j++) {
            printf(" ");
        }

        // 5. Desenha a parede direita e pula a linha
        printf("|\n");

        Sleep(33);
    }
    return 0;
}
