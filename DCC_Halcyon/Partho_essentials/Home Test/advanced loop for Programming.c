#include<stdio.h>

int main()
{
    int a =0 , b = 0 , sum, n , i, m;

    scanf("%d", &n);

    i = 1;
    while ( i <= n )
    {
        i++;
        scanf("%d",&m);
        int j;
        j = 1 ;
        while ( j <= m)
            {
                j++;
                scanf("%d", &a);
                b = b + a;

            }

            printf("%d\n",b);
            b = 0;
    }



    return 0;
}
