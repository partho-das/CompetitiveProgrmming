/// Strong number between 1 to n.
///Loop statement.

#include<stdio.h>

int main()

{
    int n,i,j,ar[100000],s = 1,fact[100000],sum = 0,m,last;

    scanf("%d",&last);
    for( n = 1 ; n<= last ; n++)
    {
        sum = 0;
        m = n;
        s = 1;
        for( i = 0; (m/10); i++ )
        {
            m = m/10;
            s++;
        }
            m = n;

        for(i = 0 ; i < s; i++ )
        {
            ar[i] = m % 10;
            m = m/10;
            fact[i]= 1;
            for(j = 1; j <=ar[i] ; j++ )
                fact[i] = fact[i]*j;

            sum = fact[i] + sum;
        }
        if(sum == n)
        printf("%d\n",n);
    }



    return 0;
}
