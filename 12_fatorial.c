#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double valor;
    double fat = 1.0;

    scanf("%lf", &valor);
    double num = trunc(valor);

    if (num == 0) {
        printf("%.0lf", fat);
    }
    else if (num < 0) {
        printf("ERRO");
    }
    else {
        for (fat; num > 1; num--) {
            fat = fat * num;
        }
        printf("%.0lf", fat);
    }
}
