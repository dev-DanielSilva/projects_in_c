#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char sentences[10][100];
char txt[100];
int i, j;

int accent (char str[]) {
    for (j = 0; str[j] != '\0'; j++) {
        unsigned char c = str[j];
        if (c > 127) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    for (i = 0; i < 10; i++) {
        fflush(stdin);
        fgets(txt, sizeof(txt), stdin);
        if(accent(txt)){
            printf("Error! Sentence with accent!");
            break;
        }
        strcpy(sentences[i], txt);
    }
    for (i = 0; i < 10; i++){
        printf("%s", sentences[i]);
    }

    return 0;
}

