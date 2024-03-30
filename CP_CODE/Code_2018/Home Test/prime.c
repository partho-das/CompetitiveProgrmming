#include<stdio.h>

int main()
{
    int m, n, t, i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d", &m, &n);
        if(m < n)
        {       m = m +1;
            for( m ; m <= n ; m++ )

            {
                printf("%d",m);
                //for( m ; m < n ; m++ )



            }
        }
    }
    return 0;
}
