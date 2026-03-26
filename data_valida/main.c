#include <stdio.h>
#include <stdlib.h>

int dia, mes, ano;

int main()
{
    scanf("%d %d %d", &dia, &mes, &ano);

    if (ano >= 0 && ano <= 2026) {
        if ((ano % 400) == 0 || (ano % 4) == 0 && (ano % 100) != 100 ) {  // Ano divisível por 400 (bissexto)
            if (mes >= 1 && mes <= 12) {
                switch (mes) {
                    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                        if (dia >= 1 && dia <= 31) {
                            printf("VALID DATE");
                        } else {
                            printf("INVALID DATE");
                        }
                        break;
                    case 4: case 6: case 9: case 11:
                        if (dia >= 1 && dia <= 30) {
                            printf("VALID DATE");
                        } else {
                            printf("INVALID DATE");
                        }
                        break;
                    case 2:
                        if (dia >= 1 && dia <= 29) {  // Fevereiro com 29 dias
                            printf("VALID DATE");
                        } else {
                            printf("INVALID DATE");
                        }
                        break;
                    default:
                        printf("INVALID DATE");
                }
            } else {
                printf("INVALID DATE");
            }
        }
        else {  // Ano não divisível por 400 (não bissexto)
            if (mes >= 1 && mes <= 12) {
                switch (mes) {
                    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                        if (dia >= 1 && dia <= 31) {
                            printf("VALID DATE");
                        } else {
                            printf("INVALID DATE");
                        }
                        break;
                    case 4: case 6: case 9: case 11:
                        if (dia >= 1 && dia <= 30) {
                            printf("VALID DATE");
                        } else {
                            printf("INVALID DATE");
                        }
                        break;
                    case 2:
                        if (dia >= 1 && dia <= 28) {  // Fevereiro com 28 dias
                            printf("VALID DATE");
                        } else {
                            printf("INVALID DATE");
                        }
                        break;
                    default:
                        printf("INVALID DATE");
                }
            } else {
                printf("INVALID DATE");
            }
        }
    } else {
        printf("INVALID DATE");
    }

    return 0;
}
