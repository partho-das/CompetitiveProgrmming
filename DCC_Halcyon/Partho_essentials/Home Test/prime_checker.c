#include<stdio.h>

int main()
{
    int number, i =1 , xpo, m,n ,j,a,b = 0,t;
    scanf("%d",&t);
    while(t--)
{
    b =0;
    scanf("%d%d",&m,&n);
    /*if(m > n )
    {
    a = m;
    m = n;
    n = a;
    }*/
    start:
    if(m <= n)
    {


    for(j = m ; j<= n ; j++ )
    {
        number =j;
        xpo = 1;
        if(j == 1)
        xpo = 0;
    for( i = 2 ; i<number ; i++ )
    {
        if( number%i == 0 )
            xpo = 0;

    }
    if(xpo == 1)
        b = b+number;

    }
        printf("%d " ,b);
    }

       else
       {
            a = m;
            m = n;
            n = a;
            goto start;
       }
        /* {
            for( j = n; j<=m ; j++ )
        {
            xpo = 1;
            if (j == 1 )
                xpo = 0;
                number = j;

        for(i = 2 ; i < number ; i++)
        {
            if (number%i == 0 )
                xpo = 0;
        }
       if( xpo == 1)
        b = b + number;
        }
        printf("%d",b);
        }*/
}
    return 0;
}
