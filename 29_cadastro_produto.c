#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int id, codigos[10];
double valor, valores[10];
double soma = 0;
char txt[30], desc[10][30];

int main()
{
    int count = 0;

    for (int i = 0; i < 10; i++){
        int repetido = 0;
        fflush(stdin);
        fgets(txt, sizeof(txt), stdin);
        if (txt[0] < '0' || txt[0] > '9'){
            printf("Valor invalido\n");
        }
        else {
            id = atoi(txt);
            for (int j = 0; j < i; j++){
                if(codigos[j] == id){
                    printf("Valor repetido");
                    repetido = 1;
                    break;
                }
            }
            if (repetido == 1){
                i--;
                continue;
            }
            else if (repetido != 1){
                codigos[i] = id;
            }
        }

        fgets(desc[i], 30, stdin);
        desc[i][strcspn(desc[i], "\n")] = 0;

        fgets(txt, sizeof(txt), stdin);
        if (txt[0] < '0' || txt[0] > '9'){
            printf("Valor invalido\n");
        }
        else {
            valor = atof(txt);
            valores[i] = valor;
            soma += valor;
        }
    }
    while (count < 10){
        printf("%d\n", codigos[count]);
        printf("%s\n", desc[count]);
        printf("%.2lf\n", valores[count]);
        count++;
    }
    printf("%.2lf", soma);

}
