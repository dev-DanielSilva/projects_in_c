#include <stdio.h>
#include <stdlib.h>

int n;
char txt[30];

int main()
{
    fflush;
    fgets(txt, sizeof(txt), stdin);
    n = atoi(txt);

    int cont = 1;
    double fatorial = 1.0;

    do {
        fatorial = fatorial * (double)cont;
        cont++;
    }
    while (cont <= n);
    printf("%.0lf", fatorial);
}
