#include <stdio.h>
#include<string.h>

int main()
{
    int test,v1,v2,sum = 0,i,j;


    scanf("%d",&test);
    for(i= 1;i<=test;i++)
    {
        sum = 0;

        scanf("%d%d",&v1,&v2);

        for(j = v1;j<=v2;j++)
        if(j&1)
            sum+=j;
        printf("Case %d: %d\n",i,sum);

    }

    return 0;
}
