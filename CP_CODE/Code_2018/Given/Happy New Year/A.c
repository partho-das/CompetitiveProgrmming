#include <stdio.h>

int main()
{
    float n;
    int i = 0;
    while(scanf("%f", &n) != EOF)
    {
        printf("Person %d: %0.2f\n", ++i, n / 4);
    }
    return 0;
}
