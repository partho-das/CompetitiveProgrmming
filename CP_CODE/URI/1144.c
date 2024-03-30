#include<stdio.h>

int main()
{
    int nu,i,j,te,ans;
    scanf("%d",&nu);

    for(i = 1;i<=nu;i++)
    {
        ans = 1;
        for(j=1;j<=3;j++)
        {
            ans *=i;
            printf("%d",ans);
            if(j!=3)
            {
                printf(" ");
            }
        }
        printf("\n");
        printf("%d",i);
        ans = 1;
        for(j=1;j<=3;j++)
        {
            ans *=i;
            if(j!=1)
            printf("%d",(ans+1));
            if(j!=3)
            {
                printf(" ");
            }

        }
        printf("\n");
    }

    return 0;
}


