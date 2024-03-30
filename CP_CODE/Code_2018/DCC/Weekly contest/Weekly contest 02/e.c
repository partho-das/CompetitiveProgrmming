#include<stdio.h>

int main()
{
    long long n=1,i = 1,j,ans =1,sum= 0;

    while(scanf("%lld",&n), n)
    {
        sum = (n*(n+1)*(2*n+1))/6;
        printf("%lld\n",sum);
    }
    return 0;
}
