#include <stdio.h>
#include <stdlib.h>
int main()
{
    char text[50];

    fflush(stdin);
    fgets(text, sizeof(text), stdin);
    for (int i = 0; i < 50; i++){
        if (text[i] <= 31) {text[i] = '\0'; break;}
    }
    printf("Hello!\n");
    printf("%s\n", text);
    return 0;
}
