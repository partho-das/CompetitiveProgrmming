#include <stdio.h>

/*int binary(unsigned int x)
{
    int arr[4], i = 0;
    while(x > 0)
    {
        arr[i++] = x % 2;
        x /= 2;
    }
    return arr;
}*/

int main()
{
    int p1, p2, p[5], pp[5], i = 0, p1i, p2i, count[7];
    int p1s[7] = {0, 0, 0, 0, 0, 0, 0};
    int p2s[7] = {0, 0, 0, 0, 0, 0, 0};
    scanf("%d%d", &p1, &p2);
    while(p1 > 0)
    {
        p[i++] = p1 % 2;
        p1 /= 2;
    }
    for(p1i = 6; p1i >= 0; p1i--) p1s[p1i] = p[p1i];
    for(p1i = 0; p1i < 6; p1i++) printf("%d", p1s[p1i]);
    i = 0;
    while(p2 > 0)
    {
        pp[i++] = p2 % 2;
        p2 /= 2;
    }
    for(p2i = 6; p2i >= 0; p2i--) p2s[p2i] = pp[p2i];
    for(p2i = 0; p2i < 6; p2i++) printf("%d", p2s[p2i]);
    return 0;
}
