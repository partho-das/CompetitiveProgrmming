#include<stdio.h>

int main()

{
    int a, b, cma;

    cma = ( a = 5, b = 4, a = 6);

    printf("%d", cma);

    return 0;
}
