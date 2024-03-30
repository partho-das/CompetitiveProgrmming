#include <stdio.h>

int main()
{
    unsigned long n;
    while(scanf("%lu", &n) != EOF)
    {
        printf("%lu\n", (n * (n + 1)) / 2);
    }
    return 0;
}
