#include <stdio.h>
#include <stdlib.h>

char texto[100];

int main()
{
    scanf("%s", texto);
    for (int i = 0; texto[i] != '\0'; i++) {
        texto[i] = texto[i] + 1;
    }
    printf("%s", texto);
}
