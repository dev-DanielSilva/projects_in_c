#include <stdio.h>
#include <stdlib.h>

float values[10];
float value;
char txt[30];

int main()
{
    int i;
    for (i = 0; i < 10; i++){
        fflush(stdin);
        fgets(txt, sizeof(txt), stdin);
        if (txt[0] < '0' || txt[0] > '9') {
            printf("Nao eh numero\n"); i=i-1; continue;
        }
        value = atof(txt);
        values[i] = value;
    }
    for (i = 0; i < 10; i++){
        printf("%.2f\n", values[i]);
    }
    return 0;
}
