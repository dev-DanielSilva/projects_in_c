#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// ANOTAÇÃO PRO FUTURO
// A função tolower deve ser usada dentro de um loop (for, while...0), para que
// funcione corretamente!

//Essa função fará com que todos os caracteres do nome sejam convertids para lower case
void paraMinusculo (char str[]){
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main()
{
    char nome1[30], nome2[30];
    scanf("%s %s", nome1, nome2);
    //Aqui haverá duas chamadas da função para trocar os caracteres para minusculo, tanto do nome1 quanto do nome2
    paraMinusculo(nome1);
    paraMinusculo(nome2);

    //Compara o conteúdo do nome1 e nome2
    if (strcmp(nome1, nome2) == 0) {
        printf("IGUAL");
    }
    else {
        printf("DIFERENTE");
    }
}
