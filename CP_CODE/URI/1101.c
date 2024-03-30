#include<stdio.h>

int main()
{
    int start,end,i,s = 0;
    while(1)
    {   s = 0;
        scanf("%d%d",&start,&end);
        if( start <=0||end<=0)
            return 0;
        if(start<end)
        for(i = start; i<=end;i++)
        {
            printf("%d ",i);
            s+=i;
        }
        else
            for(i = end;i<=start;i++)
        {
             printf("%d ",i);
            s+=i;
        }
        printf("Sum=%d\n",s);

    }

    return 0;
}
