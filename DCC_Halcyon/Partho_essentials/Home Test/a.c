#include<stdio.h>

int main()
{
    int n,a,b,c = 0, d = 0;

    scanf("%d",&n);


    for( a = 1 ; a<=n; a++ )
    {
        for(b = 1; b<=a; b++)
        {
            if(a>=1&&b<=n&&(a%b)==0&&(a*b>n)&&((a/b)<n))
            {
                c = a;
                d = b;
            }

        }
    }
    if(c != 0 && d != 0 )
    {
        printf("%d %d\n",c,d);
    }
    else
            printf("-1\n");

    return 0;
}
