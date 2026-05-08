#include <stdio.h>

int main()
{
    float n1, n2, n3, p1 = 1, p2 = 2, p3 = 3, media;
    scanf("%f %f %f", &n1, &n2, &n3);
    media = (n1 * p1 + n2 * p2 + n3 * p3) / (p1 + p2 + p3);
    printf("%.2f\n", media);
    return 0;
}