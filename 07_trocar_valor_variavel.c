#include <stdio.h>
#include <stdlib.h>

int a, b, c;

int main()
{
    if(scanf("%d%d", &a, &b) == 2) {
        c = a;
        a = b;
        b = c;
        printf("%d\n", a); printf("%d\n", b);
    } else {
        printf("Valor invalido");
    }

    return 0;
}
