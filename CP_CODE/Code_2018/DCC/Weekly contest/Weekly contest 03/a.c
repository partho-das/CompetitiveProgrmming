#include<stdio.h>

int main()
{
    int test,i,sum = 0,n,j;

    scanf("%d",&test);

    for(i= 0;i<test;i++)
    { sum = 0;
            scanf("%d",&n);
        for(j = 1;j<n;j++)
        {
            if(n%j==0)
                sum+=j;
        }
        printf("%d",sum);
    }

    return 0;
}
