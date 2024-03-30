#include <stdio.h>

int main()
{
    unsigned int x, y;
    while(scanf("%u%u", &x, &y) != EOF)
    {
        printf("%0.2f%%\n", (float)(100 / (float)x) * (float)y);
    }
    return 0;
}
