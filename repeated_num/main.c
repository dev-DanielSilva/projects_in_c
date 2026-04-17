#include <stdio.h>
#include <stdlib.h>

int valores[10], valor;
char txt[30];

int main()
{
    for (int i = 0; i < 10; i++){
        fflush(stdin);
        fgets(txt, sizeof(txt), stdin);
        valor = atoi(txt);

        int repeat = 0;
        for (int j = 0; j < i; j++){
            if (valor == valores[j]){
                repeat = 1;
                break;
            }
        }
        if (repeat) {
            i--;
        } else {
            valores[i] = valor;
        }

    }
    for (int k = 0; k < 10; k++){
        printf("%d\n", valores[k]);
    }
}
