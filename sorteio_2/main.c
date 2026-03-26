#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max;

int main()
{
    scanf("%d", &max);
    srand(time(NULL));
    int random_number = rand() % (max + 1);
    printf("%d", random_number);

    return 0;
}
