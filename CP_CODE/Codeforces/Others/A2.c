#include<stdio.h>

int main()
{
    int te,n,now,go,rate,i,j;

    scanf("%d",&te);

    for(i = 0; i<=te; i++)
    {
        scanf("%d%d%d%d",&n,&now,&go,&rate);
        int s = 0;

        if(abs(n-now-go)>abs(now-1-go))
        {
            for(j = now; j>=1; j= j-rate )
            {
            s++;
            if(j == go)
            {
            printf("%d",s);
            break;
            now = 0;
            }
            }
            for(j = 0;j <= go; j = j + rate )

                s++;
                if(j == go){
                printf("%d",s);
                break;
                }
                else
                    printf("-1");
        }

            if(abs(n-now-go)<abs(now-1-go))
        {
            for(j = now; j<= now; j= j+rate )
            {
            s++;
            if(j == go)
            {
            printf("%d",s);
            break;
            now = 0;
            }
            }
            for(j = 0;j >= 1; j = j + rate )
            {
                s++;
                if((j == go)){
                printf("%d",s);
                break;
                }
                else
                    printf("-1");
        }     }
    }

    return 0;
}
