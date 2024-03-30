#include<stdio.h>

int main()
{
    long long int n,res = 0;

   while( scanf("%lld",&n) !=EOF)
   {



    res = (n*(1+n))>>1;

    printf("%lld\n",res);

   }



    return 0;
}
