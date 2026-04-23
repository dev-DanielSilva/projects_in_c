#include <stdio.h>
#include <stdlib.h>

int main()
{
    float tempF, tempC;
    scanf("%f", &tempF);
    if (tempF >= -50.0 && tempF <= 150)
    {
       tempC = ((tempF - 32.0) * 5.0)/9.0;
       printf("%.2f\n", tempC);
    }
    else
    {
        printf("Digite um valor valido.");
    }

    return 0;
}
