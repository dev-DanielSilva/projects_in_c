#include <stdio.h>
#include <stdlib.h>

int num, vetor1[10], vetor2[10], vetorSoma[20];
char txt[30];

int main()
{
    //Inicia contagem
    int count = 0;
    //Adicao de valores ao vetor1
    while (count < 10){
        fgets(txt, sizeof(txt), stdin);
        if ((txt[0] < '0' || txt[0] > '9') && txt[0] != '-'){
            printf("Valor invalido\n");
        }
        else {
            num = atoi(txt);
            vetor1[count] = num;
            count++;
        }
    }
    //Reseta contagem
    count = 0;
    //Adicao de valores ao vetor2
    while (count < 10){
        fgets(txt, sizeof(txt), stdin);
        if ((txt[0] < '0' || txt[0] > '9') && txt[0] != '-'){
            printf("Valor invalido\n");
        }
        else {
            num = atoi(txt);
            vetor2[count] = num;
            count++;
        }
    }
    //Adicao dos valores de vetor1 e vetor2 ao vetorSoma
    for (int i = 0; i < 10; i++){
        vetorSoma[i] = vetor1[i];
        vetorSoma[i + 10] = vetor2[i];
    }
    //Ordena os valores em ordem crescente
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 19 - i; j++){
            if (vetorSoma[j] > vetorSoma[j+1]){
                int temp = vetorSoma[j];
                vetorSoma[j] = vetorSoma[j+1];
                vetorSoma[j+1] = temp;
            }
        }
    }
    //Printa o vetorSoma
    for (int i = 0; i < 20; i++){
        printf("%d\n", vetorSoma[i]);
    }
    return 0;
}
