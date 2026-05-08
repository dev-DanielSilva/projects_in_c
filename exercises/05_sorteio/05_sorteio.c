#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, sorteio;
    srand(time(0));
    scanf("%d", &n);
    sorteio = rand() % n + 1;
    printf("%d\n", sorteio);
    return 0;
}