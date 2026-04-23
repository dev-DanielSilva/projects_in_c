#include <stdio.h>
#include <stdlib.h>

int a, b, c, temp;

int main()
{
    scanf("%d%d%d", &a, &b, &c);
    if (a > b) {
       temp = a;
       a = b;
       b = temp;
    }
    if (a > c) {
        temp = a;
        a = c;
        c = temp;
    }
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }
    printf("%d\n%d\n%d\n", a, b, c);
}
