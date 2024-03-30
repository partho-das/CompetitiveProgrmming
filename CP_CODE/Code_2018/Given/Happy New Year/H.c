#include <stdio.h>
#include <math.h>

int main()
{
    unsigned int t, i;
    scanf("%u", &t);
    for(i = 1; i <= t; i++)
    {
        float a, b, c, s, r;
        scanf("%f%f%f", &a, &b, &c);
        s = (a + b + c) / 2;
        r = (sqrt(s * (s - a) * (s - b) * (s - c))) / s;
        printf("Case #%u: %0.2f\n", i, r);
    }
    return 0;
}
