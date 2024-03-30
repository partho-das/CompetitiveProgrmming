#include<stdio.h>

int main()
{
    int n,i,sum = 0,cnt = 0;

    while(1)
    {
        scanf("%d",&n);
        sum = 0;
        cnt = 0;
        if(n==0)
        return 0;

            for(i= n;cnt<5;i++)
            {
                if(i%2==0)
                {
                    cnt++;
                    sum+=i;
                }
            }
            printf("%d\n",sum);
    }


    return 0;
}
