#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double angulo_graus;
    double pi = 3.1415926;

    scanf("%lf", &angulo_graus);
    double angulo_rad = (angulo_graus * pi)/180;

    printf("%.4lf\n", sin(angulo_rad));
    printf("%.4lf\n", cos(angulo_rad));

    return 0;
}
