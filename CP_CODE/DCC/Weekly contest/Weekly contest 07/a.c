#include<stdio.h>
int main()
{
    long long cs = 1,i,sum = 0,n;

    while(scanf("%lld",&n) !=EOF)
    {
        sum = 0;
      sum = (n*(n+1))/2;

        printf("Case %lld: %lld\n",cs++,sum);
    }


    return 0;
}
