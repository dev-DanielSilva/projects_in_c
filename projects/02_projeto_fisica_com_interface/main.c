#include "raylib.h"

int main() {
    const int larguraTela = 800;
    const int alturaTela = 450;
    InitWindow(larguraTela, alturaTela, "Simulador de Movimento");

    float posicao = 0.0;
    float velocidade = 1.0;
    float aceleracao = 0.0;

    int limite_esquerdo = 0;
    int limite_direito = 60;

    const int escalaX = 12;
    const int deslocamentoX = 40;
    const int tamanhoBloco = 30;

    SetTargetFPS(60);

    // Loop principal do programa
    while (!WindowShouldClose()) {

        if (IsKeyPressed(KEY_W)) {
            aceleracao += 0.01f;
        }
        else if (IsKeyPressed(KEY_S)) {
            aceleracao -= 0.01f;
        }
        else if (IsKeyPressed(KEY_SPACE)) {
            aceleracao = 0.0f;
        }

        // ---- LÓGICA DA FÍSICA ----
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

        // ---- RENDERIZAÇÃO (INTERFACE GRÁFICA) ----
        BeginDrawing();
            ClearBackground(RAYWHITE); // Limpa a tela com fundo branco

            // Exibe as informações de texto na tela
            DrawText(TextFormat("Posicao: %.2f | Velocidade: %.2f | Aceleracao: %.2f", posicao, velocidade, aceleracao), 20, 20, 20, DARKGRAY);
            DrawText("Use W/S para acelerar/desacelerar e ESPACO para zerar a aceleracao", 20, 50, 18, MAROON);

            // Desenha as "paredes" de limite (linhas verticais)
            int posX_limite_esquerdo = (limite_esquerdo * escalaX) + deslocamentoX;
            int posX_limite_direito = (limite_direito * escalaX) + deslocamentoX + tamanhoBloco;

            DrawLine(posX_limite_esquerdo, 150, posX_limite_esquerdo, 250, BLACK);
            DrawLine(posX_limite_direito, 150, posX_limite_direito, 250, BLACK);

            // Calcula a posição atual do bloco na tela gráfica
            int blocoX = (int)(posicao * escalaX) + deslocamentoX;
            int blocoY = 190; // Altura fixa para o bloco se mover horizontalmente

            // Desenha o bloco (representando o seu 'X')
            DrawRectangle(blocoX, blocoY, tamanhoBloco, tamanhoBloco, BLUE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
