#include<stdio.h>

int main()

{
    int n,i,j,k;

    scanf("%d",&n);
    int r[n*100];

   for( i = 0; i < n ;i ++ )
    {

        for( j = (100*i); j < 100*(i+1); j++ )
        {
            scanf("%d",r[j]);
        }

    }

    for( i = 0; i < 100; i++ )

    {
        if(r[i] != 0)
        {
            tx:
             for(k = 1; k <= n; )
            for(j = (k*100) ; j< (100+k*100) ; j++  )
            {
                if(r[i] = r[j])
                {
                    if(k == n);
                    printf("%d",r[i]);
                    k++;
                    goto tx;


                }

            }
        }
    }


}
