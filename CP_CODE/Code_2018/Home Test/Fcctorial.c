#include<stdio.h>

int main()
{
    int n, i = 1 , ans = 1;

    scanf("%d",&n);

    if(  n == 0 )
    {
        printf("1\n");

    }
     else
        {
            for(  i = 1 ; i <= n ; i++ )
            {

            ans *= i;
            }

            printf("%d\n", ans);
        }
    return 0;
}
