#include<stdio.h>
#define dbg(x) printf("%s = %d\n", #x, x)

int main()
{
    int n, b, sum = 1;

    scanf("%d",&n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&b);
        sum *=b; dbg(sum);
    }

    return 0;
}
