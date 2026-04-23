#include <stdio.h>
#include <stdlib.h>

float values[10];
float num;

int main()
{
    for (int i = 0; i < 10; i++){
        scanf("%f", &num);
        values[i] = num;
    }
    for (int i = 0; i < 10; i++){
        printf("%.2f\n", values[i]);
    }
}
