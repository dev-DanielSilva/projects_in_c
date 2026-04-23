#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n;
    float somatoria = 0;

    for (int i = 0; i < 10; i++) {
        scanf("%f ", &n);
        somatoria = somatoria + n;
    }

    float media = somatoria/10.0;

    printf("%.2f\n", somatoria);
    printf("%.2f\n", media);
}
