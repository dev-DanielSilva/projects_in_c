#include <stdio.h>

int main()
{
    float a, b;
    int opcao;
    scanf("%f %f %d", &a, &b, &opcao);
    switch(opcao) {
        case 1: printf("%.2f\n", a + b); break;
        case 2: printf("%.2f\n", a - b); break;
        case 3: printf("%.2f\n", a * b); break;
        case 4: if(b != 0) printf("%.2f\n", a / b); break;
    }
    return 0;
}