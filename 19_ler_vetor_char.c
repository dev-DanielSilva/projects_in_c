#include <stdio.h>
#include <stdlib.h>

char word[10];

int main()
{
    char text[10];
    int i;

    for (i = 0; i < sizeof(word); i++){
        fflush(stdin);
        fgets(text, sizeof(text), stdin);
        word[i] = text[0];
    }
    for (i = 0; i < sizeof(word); i++) {
        printf("%c", word[i]);
    }
}
