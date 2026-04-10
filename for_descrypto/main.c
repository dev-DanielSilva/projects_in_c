#include <stdio.h>
#include <stdlib.h>

char text[100];

int main()
{
    scanf("%s", text);
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = text[i] - 1;
    }
    printf("%s", text);
}
