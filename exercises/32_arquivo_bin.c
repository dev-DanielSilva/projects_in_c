#include <stdio.h>
#include <stdlib.h>
#define VALOR_FINAL 42.0f

FILE *Arquivo;
float Vetor[100];

int main()
{
    int Repetir;
    int TotNum;
    int i;
    // Declara o Arquivo para salvar os valores como Nros-salvos.bin
    Arquivo = fopen("Nros-salvos.bin", "wb");
    if (Arquivo == NULL){
        printf("Erro na criacao do arquivo!");
        exit(0);
    }
    Repetir = 1;
    i = 0;
    while (Repetir) {
        printf("Entre com o nro. %d : \n", i);
        scanf("%f", &Vetor[i]);
        // Se o nro = 42, o loop se encerra
        if (Vetor[i] == 42.0f){
            //Totnum é a quantidade total de números
            TotNum = i;
            Repetir = 0;
        }
        i++;
    }
    printf("Total de numeros lidos: %d\n", TotNum);

    fwrite(Vetor, sizeof(double), TotNum, Arquivo);
    fclose(Arquivo);
    return 0;
}
