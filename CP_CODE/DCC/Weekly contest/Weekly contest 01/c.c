#include<stdio.h>

int main()
{
    int n,x=2000,s = 0,i,cn = 0;
    while(x)
    {
        s = 0;
        scanf("%d",&n);
        if(n<0)
            return 0;
        for(i = 2; i<=n;i = i+i)
        {
            s++;
        }
        x--;
        if(n<i&& n>(i/2))
            s++;
            cn++;

        printf("Case %d: %d\n",cn,s);
    }
    return 0;
}
