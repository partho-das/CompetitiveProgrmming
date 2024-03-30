#include<stdio.h>

int main()
{
    int a,b,n,sum,i;


    scanf("%d",&n);

    for(i = 1;i<=n;i++)
    {

        scanf("%d%d",&a,&b);

        sum = a+b;
        printf("Case %d: %d\n",i,sum);
    }

    return 0;
}

