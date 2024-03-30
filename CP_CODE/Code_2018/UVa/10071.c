#include<stdio.h>

int main()
{
    int v, t,d;
    while(scanf("%d%d", &v, &t) !=EOF)
    {
        d = v*t;
        //for 2nd times
        d = d*2;
        printf("%d\n",d);
    }
    return 0;
}
