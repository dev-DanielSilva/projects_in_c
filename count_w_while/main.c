#include <stdio.h>
#include <stdlib.h>

char txt[30];
int n;

int main()
{
    fflush(stdin);
    fgets(txt, sizeof(txt), stdin);
    n = atoi(txt);

    int cont = 1;

    if (n < 1) {
        printf("Valor invalido");
    }

    else {
        while (cont <= n){
            printf("%d\n", cont);
            cont++;
        }
        cont = n;
        while(cont >= 1){
            printf("%d\n", cont);
            cont--;
        }
    }

}
