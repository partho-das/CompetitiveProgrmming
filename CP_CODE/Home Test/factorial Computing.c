#include<stdio.h>

int main()
{
    int n, i = 1 , ans = 1;

    while( scanf("%d",&n) !=EOF)
    {

    ans =1;
    for( i = 1; i <= n ; ans *= i++ );
    printf("%d\n", ans);
    }

    return 0;
}
