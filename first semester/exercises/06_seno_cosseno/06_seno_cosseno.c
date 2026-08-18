#include <stdio.h>
#include <math.h>

int main()
{
    double angulo, radianos, seno, cosseno;
    scanf("%lf", &angulo);
    radianos = angulo * M_PI / 180;
    seno = sin(radianos);
    cosseno = cos(radianos);
    printf("%.4f %.4f\n", seno, cosseno);
    return 0;
}