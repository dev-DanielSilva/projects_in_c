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

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        if (IsKeyDown(KEY_W)) {
            aceleracao += 2.0f * dt;
        }
        else if (IsKeyDown(KEY_S)) {
            aceleracao -= 2.0f * dt;
        }
        else if (IsKeyPressed(KEY_SPACE)) {
            aceleracao = 0.0f;
        }
        if (!IsKeyDown(KEY_W) && !IsKeyDown(KEY_S)) {
            // Reduz a velocidade gradualmente com base no tempo (dt)
            // O valor 2.0f controla a "força" do atrito (quanto maior, mais rápido ele para)
            if (velocidade > 0) {
                velocidade -= 2.0f * dt;
                if (velocidade < 0) velocidade = 0; // Impede que o atrito faça o bloco andar para trás
            }
            else if (velocidade < 0) {
                velocidade += 2.0f * dt;
                if (velocidade > 0) velocidade = 0; // Impede que o atrito faça o bloco andar para a frente
            }
        }
        velocidade += aceleracao * dt;
        posicao += velocidade * dt;

        if (posicao >= limite_direito) {
            posicao = limite_direito;
            velocidade = -velocidade * 0.6f;
        }
        else if (posicao <= limite_esquerdo) {
            posicao = limite_esquerdo;
            velocidade = -velocidade * 0.6f;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawText(TextFormat("Posicao: %.2f | Velocidade: %.2f | Aceleracao: %.2f", posicao, velocidade, aceleracao), 20, 20, 20, DARKGRAY);
            DrawText("Use W/S para acelerar/desacelerar e ESPACO para zerar a aceleracao", 20, 50, 18, MAROON);

            int posX_limite_esquerdo = (limite_esquerdo * escalaX) + deslocamentoX;
            int posX_limite_direito = (limite_direito * escalaX) + deslocamentoX + tamanhoBloco;

            DrawLine(posX_limite_esquerdo, 150, posX_limite_esquerdo, 250, BLACK);
            DrawLine(posX_limite_direito, 150, posX_limite_direito, 250, BLACK);

            int blocoX = (int)(posicao * escalaX) + deslocamentoX;
            int blocoY = 190;

            DrawRectangle(blocoX, blocoY, tamanhoBloco, tamanhoBloco, BLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
