#include<stdio.h>

int main()

{
    int i,start,end,n,k, sum =0 ;

    scanf("%d",&n);

    for(i = 1; i <= n; i++ )
        {
    scanf("%d%d",&start,&end);
        sum = 0;
        for(k = start ; k<= end ; k++)
        {

        if( k%2 == 0)
        {
            sum = sum +k;
        }
        else
            sum = sum - k;
        }
        printf("%d\n",sum);
    }


}
